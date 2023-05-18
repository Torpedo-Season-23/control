# Console
* This project is the program uploaded on the MCU located in the outer control-box.
* MCU receives signals from a joystick, processes these signals to create a motion frame of forces Fx, Fy and Mz.
* PID control system is applied to these motion forces.
* The MCU in the control-box communicates with NanoX using Ethernet protocol and sends to it the motion frame.

# BOX
* The box contains 3 MCUs which communicate with each other using UART communication protocol.
* Opensource libraries are used such as MPU6050, Servo, etc...

