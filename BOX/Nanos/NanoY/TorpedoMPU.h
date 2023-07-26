//DONE

#ifndef _TorpedoMPU_H_
#define _TorpedoMPU_H_
//#include "lib/MPU6050/I2Cdev.cpp"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include <Wire.h>
#endif

class TorpedoMPU : public MPU6050 {
private:
  Quaternion myQuatOffset;
  bool dmpReady;
  uint8_t mpuIntStatus, devStatus;
  uint16_t packetSize, fifoCount;
  uint8_t fifoBuffer[64];
  Quaternion q;
  VectorFloat gravity;
  float ypr[3];
  volatile bool mpuInterrupt;
  boolean stable_1, stable_2;
  float myYawOffset;
  long Time;
  float sinYaw, cosYaw, sinPitch, cosPitch, sinRoll, cosRoll;
  float x2, z2;
  float accx, accy, accz;
  float gyrx, gyry, gyrz;
  float roll, pitch, yaw_3;
public:
  int angles[3];

private:

  static TorpedoMPU::QuaternionChange(float x, float y, float z) {
    return new Quaternion(x, y, z, 1);
  }
  void TorpedoMPU::SetOffset(Quaternion *offset, Quaternion *q) {
    offset->w = q->w;
    offset->x = q->x;
    offset->y = q->y;
    offset->z = q->z;
  }
  float TorpedoMPU::getYaw_mine(Quaternion &q) {
    x2 = q.x * q.x;
    z2 = q.z * q.z;
    return atan2(2.0f * q.z * q.w - 2.0f * q.y * q.x, 1.0f - 2.0f * z2 - 2.0f * x2);
  }
  void TorpedoMPU::createFromYawPitchRoll_mine(float yaw_3, float pitch, float roll) {

    yaw_3 = 0.5f;
    pitch *= 0.5f;
    roll *= 0.5f;
    sinYaw = sin(yaw_3);
    cosYaw = cos(yaw_3);
    sinPitch = sin(pitch);
    cosPitch = cos(pitch);
    sinRoll = sin(roll);
    cosRoll = cos(roll);
    QuaternionChange(q.x, q.y, q.z);

#ifdef SWITCH_PITCH_AND_ROLL_AXIS
#ifdef ROTATE_180_DEGREE_Z_YAW
    q.w = cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw;
    q.x = -(sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw);
    q.y = -(cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw);
    q.z = -(sinRoll * sinPitch * cosYaw - cosRoll * cosPitch * sinYaw);
#else
    q.w = cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw;
    q.x = sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw;
    q.y = cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw;
    q.z = cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw;
#endif
#else
#ifdef ROTATE_180_DEGREE_Z_YAW
    q.w = cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw;
    q.x = -(cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw);
    q.y = -(cosRoll * sinPitch * sinYaw - sinRoll * cosPitch * cosYaw);
    q.z = -(sinRoll * sinPitch * cosYaw - cosRoll * cosPitch * sinYaw);
#else
    q.w = cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw;
    q.x = cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw;
    q.y = cosRoll * sinPitch * sinYaw - sinRoll * cosPitch * cosYaw;
    q.z = cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw;
#endif
#endif
    return q;
  }
public:
  TorpedoMPU() {
    this->roll = 0;
    this->pitch = 0;
    this->yaw_3 = 0;
    this->Time = 0;
    this->sinYaw = 0;
    this->cosYaw = 0;
    this->sinPitch = 0;
    this->cosPitch = 0;
    this->sinRoll = 0;
    this->cosRoll = 0;
    this->x2 = 0;
    this->z2 = 0;
    this->stable_2 = false;
    this->myYawOffset = 0.0f;
    this->stable_2 = false;
    this->mpuInterrupt = false;
    this->dmpReady = false;
  };
  void TorpedoMPU::start() {
    mpuInterrupt = true;
    Wire.begin();
    Wire.setClock(400000);
    while (!Serial)
      ;
    Serial.println(F("Initializing I2C devices..."));
    initialize();
    Serial.println(F("Testing device connections..."));
    Serial.println(testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    Serial.println(F("Initializing DMP..."));
    devStatus = dmpInitialize();

    setXGyroOffset(220);
    setYGyroOffset(76);
    setZGyroOffset(-85);
    setZAccelOffset(1788);
  }
  void TorpedoMPU::check() {
    if (devStatus == 0) {
      CalibrateAccel(6);
      CalibrateGyro(6);
      PrintActiveOffsets();
      Serial.println(F("Enabling DMP..."));
      setDMPEnabled(true);

      Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
      mpuIntStatus = getIntStatus();
      Serial.println(F("DMP ready! Waiting for first interrupt..."));
      dmpReady = true;
      packetSize = dmpGetFIFOPacketSize();

    } else {
      Serial.print(F("DMP Initialization failed (code "));
      Serial.print(devStatus);
      Serial.println(F(")"));
    }
  }

  void TorpedoMPU::calculate() {
    /*if (!dmpReady)
      return;*/
    mpuInterrupt = false;
    mpuIntStatus = getIntStatus();
    fifoCount = getFIFOCount();
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
      resetFIFO();
      Serial.println(F("FIFO overflow!"));
    } else if (mpuIntStatus & 0x02) {
      while (fifoCount < packetSize)
        fifoCount = getFIFOCount();
      getFIFOBytes(fifoBuffer, packetSize);
      fifoCount -= packetSize;
      dmpGetQuaternion(&q, fifoBuffer);
      dmpGetGravity(&gravity, &q);
      dmpGetYawPitchRoll(ypr, &q, &gravity);
      if (!stable_1) {
        Time = millis();
        if ((int)(2.0f * ypr[0] * 180 / M_PI) == (int)(myYawOffset)) {
          stable_2 = true;
        }
        if (stable_2) {
          if (Time + 1000 < millis())
            stable_1 = true;
        } else {
          Time = millis();
        }
        myYawOffset = 2.0f * ypr[0] * 180 / M_PI;
        SetOffset(&myQuatOffset, &q);
        if (stable_1) {
          float yaw_1 = getYaw_mine(q);
          float yaw_2 = getYaw_mine(myQuatOffset);
          float yaw_3 = yaw_1 - yaw_2;
          createFromYawPitchRoll_mine(yaw_3, pitch, roll);
        }
      }
      if (abs(yaw_3 * 180 / M_PI - ypr[0] * 180 / M_PI) > 0.5) {
        yaw_3 = ypr[0];
      }
      roll = (ypr[2] * 180 / M_PI);
      pitch = (ypr[1] * 180 / M_PI);
      yaw_3 = (yaw_3 * 180 / M_PI);
    }
    angles[0] = roll;
    angles[1] = pitch;
    angles[2] = yaw_3;
    Serial.print("roll: ");
    Serial.print(angles[0]);
    Serial.print("  pitch: ");
    Serial.print(angles[1]);
    Serial.print("   yaw: ");
    Serial.println(angles[2]);
  }
  //     float TorpedoMPU::Return_roll() {
  //       calculate();
  //       return roll;
  //     }
  //     float TorpedoMPU::Return_pitch() {
  //       calculate();
  //       return pitch;
  //     }
  //     float  TorpedoMPU::Return_yaw() {
  //       calculate();
  //       return yaw_3;
  //     }
  //    int TorpedoMPU::Return_accx() {
  //      accx = getAccelerationX();
  //      return accx;
  //    }
  //    int TorpedoMPU::Return_accy() {
  //      accy = getAccelerationY();
  //      return accy;
  //    }
  //    int  TorpedoMPU::Return_accz() {
  //      accz = getAccelerationZ();
  //      return accz;
  //    }
  //    int  TorpedoMPU::Return_gyrx() {
  //      gyrx = getRotationX();
  //      return gyrx;
  //    }
  //    int TorpedoMPU::Return_gyry() {
  //      gyry = getRotationY();
  //      return gyry;
  //    }
  //    int TorpedoMPU::Return_gyrz() {
  //      gyrx = getRotationZ();
  //      return gyrz;
  //    }
  int *TorpedoMPU::getangles() {
    calculate();
    return angles;
  }
};
#endif