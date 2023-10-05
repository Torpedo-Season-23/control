
#if !defined(__LF310_H__)
#define __LF310_H__

#include "IController.h"

#define LF310_VID 0x046D
#define LF310_PID 0xC216


enum DPADEnum {
  DPAD_UP = 0x0,
  DPAD_RIGHT = 0x2,
  DPAD_DOWN = 0x4,
  DPAD_LEFT = 0x6,
  DPAD_OFF = 0x8,
};


union LF310DataButtons {
  struct {
    uint8_t dPad : 4;
    uint8_t Xbutton : 1;
    uint8_t Abutton : 1;
    uint8_t Bbutton : 1;
    uint8_t Ybutton : 1;

    uint8_t LBbutton : 1;
    uint8_t RBbutton : 1;
    uint8_t LTbutton : 1;
    uint8_t RTbutton : 1;
    uint8_t Backbutton : 1;
    uint8_t Startbutton : 1;
    uint8_t LJSP : 1;
    uint8_t RJSP : 1;
  } __attribute__((packed));
  uint16_t val;
} __attribute__((packed));


struct LF310Data {
  uint8_t X;
  uint8_t Y;
  uint8_t Z;
  uint8_t Rz;
  LF310DataButtons btn;
  union {
    uint8_t Extra;
    struct {
      uint8_t nonfunc : 3;
      uint8_t mode : 1;
      uint8_t nonfunc2 : 4;
    };
  };
};

class LF310 : public HIDUniversal {
public:
  LF310(USB *p)
    : HIDUniversal(p) {
    lf310Data.btn.dPad = DPAD_OFF;
    lf310Data.X = 128;
    lf310Data.Y = 128;
    lf310Data.Z = 128;
    lf310Data.Rz = 128;
  };
  bool connected() {
    return HIDUniversal::isReady() && HIDUniversal::VID == LF310_VID && HIDUniversal::PID == LF310_PID;
  };

  LF310Data lf310Data;
  LF310DataButtons buttonClickState;


private:
  void ParseHIDData(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf);
  uint8_t OnInitSuccessful() {
    if (HIDUniversal::VID != LF310_VID || HIDUniversal::PID != LF310_PID)
      return 1;
    return 0;
  };
};
class Xbox : public IController {
private:
  LF310 lf310;
  void update_vmotion();
  void update_hmotion();
  bool moment;
public:
  Xbox()
    : lf310(&Usb) {}
  void Update();
  bool force_stop();
  int8_t getDirection();
  bool nrf();
  void pitching();
  bool timer();
};


#endif
