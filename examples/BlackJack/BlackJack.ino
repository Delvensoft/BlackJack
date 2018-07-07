#include "InputDevice.h";
#include "Timer.h"
InputDevice input(new AnalogInputSource(1));
void valueChange(int val);
void setup(){
  input.onValueChanged(valueChange);
}
void loop(){
  Async::checkAll();
}
void valueChange(int val){
  Serial.println(val);
}

