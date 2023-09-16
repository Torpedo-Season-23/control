#include "System.h"
#include <WebSerial.h>
System sys;
TaskHandle_t comm_task_handle;
TaskHandle_t sens_task_handle;
TaskHandle_t mot_task_handle;

#define del ( TickType_t ) 0x000000ffUL
SemaphoreHandle_t sem;
SemaphoreHandle_t sem1;

void Communication_task(void* vparameter) {
  for (;;) {
    // xSemaphoreTake(sem,portMAX_DELAY);
    sys.receiveData();
    // xSemaphoreGive(sem);
    xSemaphoreTake(sem1,portMAX_DELAY);
    sys.sendData();
    xSemaphoreGive(sem1);
    
    // vTaskDelay(10);
  }
}
void motor_task(void* vparameter) {
  for (;;) {
    // xSemaphoreTake(sem, portMAX_DELAY);
    sys.motorToolsUpdate();
    // xSemaphoreGive(sem);
    // vTaskDelay(1000);
  }
}
void sensor_task(void* vparameter) {
  for (;;) {
    xSemaphoreTake(sem1, portMAX_DELAY);
    sys.sensorsUpdate();
    xSemaphoreGive(sem1);
    vTaskDelay(40);
    // log_i( "fDoTheHumidityThing high watermark %d", uxTaskGetStackHighWaterMark( NULL ) );
  }
}

void setup() {
  Serial.begin(115200);
  sys.init();
  sem = xSemaphoreCreateMutex();
  sem1 = xSemaphoreCreateMutex();
  xTaskCreatePinnedToCore(
    Communication_task, "communication_task", 20000  // Stack size
    ,
    NULL  // When no parameter is used, simply pass NULL
    ,
    1  // Priority
    ,
    &comm_task_handle  // With task handle we will be able to manipulate with this task.
    ,
    0  // Core on which the task will run
  );
  xTaskCreatePinnedToCore(
    motor_task, "motor_task", 40000  // Stack size
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
    sensor_task, "sensor_task", 20000  // Stack size
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
