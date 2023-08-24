#include "System.h"

System sys;
TaskHandle_t comm_task_handle;
TaskHandle_t sens_task_handle;
TaskHandle_t mot_task_handle;

SemaphoreHandle_t sem;
SemaphoreHandle_t sem1;

void Communication_task(void* vparameter) {
  for (;;) {
    // bool arr[8] = { false };
    // int x;
    // if (Serial.available()) {
    //   x = Serial.read() - 48;
    //   Serial.println(x);
    //   arr[x] = true;
    //   sys.setToolsFrame(arr);
    // }
    xSemaphoreTake(sem,portMAX_DELAY);
    sys.receiveData();
    xSemaphoreGive(sem);
    xSemaphoreTake(sem1,portMAX_DELAY);
    sys.sendData();
    xSemaphoreGive(sem1);
  }
}
void motor_task(void* vparameter) {
  for (;;) {
    xSemaphoreTake(sem, portMAX_DELAY);
    sys.motorToolsUpdate();
    xSemaphoreGive(sem);
  }
}
void sensor_task(void* vparameter) {
  for (;;) {
    xSemaphoreTake(sem1, portMAX_DELAY);
    sys.sensorsUpdate();
    xSemaphoreGive(sem1);
  }
}

void setup() {
  Serial.begin(115200);
  sys.init();
  sem = xSemaphoreCreateCounting(1, 1);
  sem1 = xSemaphoreCreateCounting(1, 1);
  xTaskCreatePinnedToCore(
    Communication_task, "communication_task", 10000  // Stack size
    ,
    NULL  // When no parameter is used, simply pass NULL
    ,
    1  // Priority
    ,
    &comm_task_handle  // With task handle we will be able to manipulate with this task.
    ,
    1  // Core on which the task will run
  );
  xTaskCreatePinnedToCore(
    motor_task, "motor_task", 1024  // Stack size
    ,
    NULL  // When no parameter is used, simply pass NULL
    ,
    1  // Priority
    ,
    &mot_task_handle  // With task handle we will be able to manipulate with this task.
    ,
    1  // Core on which the task will run
  );
  xTaskCreatePinnedToCore(
    sensor_task, "sensor_task", 2048  // Stack size
    ,
    NULL  // When no parameter is used, simply pass NULL
    ,
    1  // Priority
    ,
    &sens_task_handle  // With task handle we will be able to manipulate with this task.
    ,
    0  // Core on which the task will run
  );
}

void loop() {
  vTaskDelete(NULL);
}
