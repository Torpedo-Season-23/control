System::System() {
  this->controller = new PS3GamePad();
}

System::System(IController *controller) {
  this->controller = controller;
}

void System::init() {
  this->controller->init();
}

void System::update() {
  this->controller->update();
}
