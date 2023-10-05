#include "lf310.h"
#define LIGHTS_INDEX 3
#define RIGHT_GRIPPER 2
#define BACK_LEFT_GRIPPER 0
#define BACK_RIGHT_GRIPPER 1
#define LINE_FOLLOWER_MODE 4
#define PID_MODE 5


bool NRFTrue = false;

void LF310::ParseHIDData(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf) {
  if (HIDUniversal::VID != LF310_VID || HIDUniversal::PID != LF310_PID)
    return;
  memcpy(&lf310Data, buf, min(len, MFK_CASTUINT8T sizeof(lf310Data)));
  static LF310DataButtons oldButtonState;
  if (lf310Data.btn.val != oldButtonState.val) {
    buttonClickState.val = lf310Data.btn.val & ~oldButtonState.val;
    oldButtonState.val = lf310Data.btn.val;
  }
}

void Xbox::Update() {
  this->Usb.Task();
  this->update_hmotion();
  this->update_vmotion();
  this->pitching();


  //speed
  if (this->lf310.buttonClickState.LBbutton) {
    if (this->speed > 0) this->speed--;
    this->lf310.buttonClickState.LBbutton = 0;
  }
  if (this->lf310.buttonClickState.RBbutton) {
    if (this->speed < 2) this->speed++;
    this->lf310.buttonClickState.RBbutton = 0;
  }


  //acc frame
  if (this->lf310.buttonClickState.RJSP) {
    for (int i = 0; i < 8; i++)
      this->acc_array[i] ^= 1;
    this->lf310.buttonClickState.RJSP = 0;
  }
  if (this->lf310.buttonClickState.Bbutton) {
    if (this->flags[RIGHT_GRIPPER] == 0) {
      this->acc_array[RIGHT_GRIPPER] = 1;
      this->flags[RIGHT_GRIPPER] = 1;
    } else {
      this->acc_array[RIGHT_GRIPPER] = 0;
      this->flags[RIGHT_GRIPPER] = 0;
    }
    this->lf310.buttonClickState.Bbutton = 0;
  }
  if (this->lf310.buttonClickState.Abutton) {
    if (this->flags[BACK_RIGHT_GRIPPER] == 0) {
      this->acc_array[BACK_RIGHT_GRIPPER] = 1;
      this->flags[BACK_RIGHT_GRIPPER] = 1;
    } else {
      this->acc_array[BACK_RIGHT_GRIPPER] = 0;
      this->flags[BACK_RIGHT_GRIPPER] = 0;
    }
    this->lf310.buttonClickState.Abutton = 0;
  }
  if (this->lf310.buttonClickState.Xbutton) {
    if (this->flags[BACK_LEFT_GRIPPER] == 0) {
      this->acc_array[BACK_LEFT_GRIPPER] = 1;
      this->flags[BACK_LEFT_GRIPPER] = 1;
    } else {
      this->acc_array[BACK_LEFT_GRIPPER] = 0;
      this->flags[BACK_LEFT_GRIPPER] = 0;
    }
    this->lf310.buttonClickState.Xbutton = 0;
  }
  if (this->lf310.buttonClickState.Ybutton) {
    if (this->flags[LIGHTS_INDEX] == 0) {
      this->acc_array[LIGHTS_INDEX] = 1;
      this->flags[LIGHTS_INDEX] = 1;
    } else {
      this->acc_array[LIGHTS_INDEX] = 0;
      this->flags[LIGHTS_INDEX] = 0;
    }
    this->lf310.buttonClickState.Ybutton = 0;
  }
  if (this->lf310.buttonClickState.Backbutton) {
    if (this->flags[LINE_FOLLOWER_MODE] == 0) {
      this->acc_array[LINE_FOLLOWER_MODE] = 1;
      this->flags[LINE_FOLLOWER_MODE] = 1;
    } else {
      this->acc_array[LINE_FOLLOWER_MODE] = 0;
      this->flags[LINE_FOLLOWER_MODE] = 0;
    }
    this->lf310.buttonClickState.Backbutton = 0;
  }
  if (this->lf310.buttonClickState.Startbutton) {
    if (this->flags[PID_MODE] == 0) {
      this->acc_array[PID_MODE] = 1;
      this->flags[PID_MODE] = 1;
    } else {
      this->acc_array[PID_MODE] = 0;
      this->flags[PID_MODE] = 0;
    }
    this->lf310.buttonClickState.Startbutton = 0;
  }



  switch (this->lf310.lf310Data.btn.dPad) {

    case DPAD_UP:
      // if (this->flags[5] == 0) {
      //   this->acc_array[5] = 1;
      //   this->flags[5] = 1;
      // } else {
      //   this->acc_array[5] = 0;
      //   this->flags[5] = 0;
      // }
      // this->lf310.lf310Data.btn.dPad = 0;
      // break;
    // case DPAD_UP:
    //   /*if(this->isAutonomous)
    //     this->isAutonomous= false;
    //     else{
    //     this->isAutonomous=true;
    //     this->timeOfAutonomous= millis();
    //     }*/
    //   /*if (this->flags[4] == 0) {
    //     this->acc_array[4] = 1;
    //     this->flags[4] = 1;
    //     } else {
    //     this->acc_array[4] = 0;
    //     this->flags[4] = 0;
    //     }*/
    //   this->lf310.lf310Data.btn.dPad = 0;
    //   break;
    // case DPAD_DOWN:

    //   /*if (this->flags[6] == 0) {
    //     this->acc_array[6] = 1;
    //     this->flags[6] = 1;
    //     } else {
    //     this->acc_array[6] = 0;
    //     this->flags[6] = 0;
    //     }*/
    //   // if (this->isAutonomous)
    //   //   this->isAutonomous = false;
    //   // else {
    //   //   this->isAutonomous = true;
    //   //   this->timeOfAutonomous = millis();
    //   // }
    //   this->lf310.lf310Data.btn.dPad = 0;
    //   break;
    // case DPAD_DOWN:

    //   if (this->flags[7] == 0) {
    //     this->acc_array[7] = 1;
    //     this->flags[7] = 1;
    //   } else {
    //     this->acc_array[7] = 0;
    //     this->flags[7] = 0;
    //   }
    //   this->lf310.lf310Data.btn.dPad = 0;
    //   break;
    case DPAD_OFF:
      // this->lf310.lf310Data.btn.dPad=0;
      break;
    default:
      // this->lf310.lf310Data.btn.dPad=0;
      break;
  }
}
void Xbox::update_vmotion() {

  // int8_t direction = 0;
  // if (this->PS3.getButtonPress(R2)) direction = -1;  //Down
  // else if (this->PS3.getButtonPress(L2)) direction = 1;
  // this->vertical_frame[0] = 1500 + direction * map(this->speeds[this->speed], 0, 128, 0, 400);
  // this->vertical_frame[1] = this->vertical_frame[0];

  int direction = 0;
  if (this->lf310.lf310Data.btn.LTbutton) {
    direction = 1;
    // this->lf310.buttonClickState.LTbutton = 0;
  }  //Down
  else if (this->lf310.lf310Data.btn.RTbutton) {
    direction = -1;
    // this->lf310.buttonClickState.RTbutton = 0;
  }


  if (flags[4]) {
    this->vertical_frame[0] = 1500 + direction * map(128, 0, 128, 0, 400);
    this->vertical_frame[1] = this->vertical_frame[0];
  } else {
    this->vertical_frame[0] = 1500 + direction * map(this->speeds[this->speed], 0, 128, 0, 400);
    this->vertical_frame[1] = this->vertical_frame[0];
  }
}



void Xbox::update_hmotion() {
  float Tx, Ty, Tm;
  float factor, sum;
  Tx = map(this->lf310.lf310Data.X, 0, 255, -this->speeds[this->speed], this->speeds[this->speed]);
  Ty = map(255 - this->lf310.lf310Data.Y, 0, 255, -this->speeds[this->speed], this->speeds[this->speed]);
  Tm = -map(this->lf310.lf310Data.Z, 0, 255, -this->speeds[0], this->speeds[0]);
  if (Tx < 30 && Tx > -30) Tx = 0;
  if (Ty < 30 && Ty > -30) Ty = 0;
  if (Tm < 30 && Tm > -30) Tm = 0;
  if (((Tx > 30) && Tx - Ty > 10) || ((Tx < -30) && Ty - Tx > 10)) {
    Ty = 0;
  }
  if (((Ty > 30) && Ty - Tx > 10) || ((Ty < -30) && Tx - Ty > 10)) {
    Tx = 0;
  }
  if (Tm) {
    moment = true;
  } else {
    moment = false;
  }

  sum = abs(Tx) + abs(Ty) + abs(Tm);
  // if (Tm && !Tx && !Ty) {
  //   factor = this->speeds[0] / sum;
  // }
  factor = this->speeds[this->speed] / sum;
  Tx *= factor;
  Ty *= factor;
  Tm *= factor;
  this->Td_array[0] = Tx;
  this->Td_array[1] = Ty;
  this->Td_array[2] = Tm;
}

bool Xbox::force_stop() {
  // if (this->PS3.getButtonPress(START)){
  //   return true;
  // }
  // else return false;
}



int8_t Xbox::getDirection() {
  //Y direction
  if (Td_array[1] > 21 && abs(Td_array[1]) > abs(Td_array[0]) && abs(Td_array[1]) > abs(Td_array[2])) {
    //  Serial.print("Forward");
    return FORWARD;
  }
  if (Td_array[1] < -21 && abs(Td_array[1]) > abs(Td_array[0]) && abs(Td_array[1]) > abs(Td_array[2])) {
    //  Serial.print("Backward");
    return BACKWARD;
  }
  //X direction
  if (Td_array[0] > 21 && abs(Td_array[0]) > abs(Td_array[1]) && abs(Td_array[0]) > abs(Td_array[2])) {
    //  Serial.print("Right");
    return RIGHT;
  }
  if (Td_array[0] < -21 && abs(Td_array[0]) > abs(Td_array[1]) && abs(Td_array[0]) > abs(Td_array[2])) {
    //  Serial.print("Left");
    return LEFT;
  }
  //M direction
  if (Td_array[2] > 21 && abs(Td_array[2]) > abs(Td_array[1]) && abs(Td_array[2]) > abs(Td_array[0])) {
    //  Serial.print("Right");
    return M_LEFT;
  }
  if (Td_array[2] < -21 && abs(Td_array[2]) > abs(Td_array[1]) && abs(Td_array[2]) > abs(Td_array[0])) {
    //  Serial.print("Left");
    return M_RIGHT;
  }
  //Up , Down
  if (vertical_frame[0] < 1500)
    return UP;
  if (vertical_frame[0] > 1500)
    return DOWN;
  //Stop
  return STOP;

  //M direction
  // if(Td_array[2] > 21 && abs(Td_array[2]) > abs(Td_array[0]) && abs(Td_array[2]) > abs(Td_array[1])  ){
  //    Serial.print("Moment Left");
  // }
  // if(Td_array[2] < -21 && abs(Td_array[2]) > abs(Td_array[0]) && abs(Td_array[2]) >abs(Td_array[1])  ){
  //    Serial.print("Moment Right");
  // }



  // Serial.print("x: ");
  // Serial.print(Td_array[0]);
  // Serial.print(" y: ");
  // Serial.print(Td_array[1]);
  // Serial.print(" m: ");
  // Serial.print(Td_array[2]);
}



bool Xbox::nrf() {
  return this->moment;
}
void Xbox::pitching() {

  int pitch = 0;
  //  pitch = this->lf310.lf310Data.Rz ;
  // pitch = map(this->lf310.lf310Data.Rz, 0, 255, -128, 128);
  pitch = this->lf310.lf310Data.btn.dPad;
  // Serial.println(this->lf310.buttonClickState.dPad.);

  if (pitch == DPAD_RIGHT) {
    this->vertical_frame[0] = 1500 + map(this->speeds[this->speed], 0, 128, 0, 400);
    this->vertical_frame[1] = 1500 - map(this->speeds[this->speed], 0, 128, 0, 400);
  } else if (pitch == DPAD_LEFT) {
    this->vertical_frame[0] = 1500 - map(this->speeds[this->speed], 0, 128, 0, 400);
    this->vertical_frame[1] = 1500 + map(this->speeds[this->speed], 0, 128, 0, 400);
  }
}


bool Xbox::timer() {
  return true;
}
