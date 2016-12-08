#ifndef _DEVICE_H
#define _INPUTDEVICE_H
#include "Device.h"
#include "InputSource.h";
class InputDevice : public Device{
  InputSource* in;
  Array<valueCallback> onValueUpdates;
  int val;
  void updateValue(int newValue);
  public:
  InputDevice(InputSource* input = 0){
    setInput(input);
  }
  void setInput(InputSource* input){
    this->in = input;
   
  }
  int value(){
    return this->val;
  }
  void onValueChanged(valueCallback updateValue){
    onValueUpdates.add(updateValue);
  }
};
void InputDevice::updateValue(int newValue){
   this->val = newValue; 
   for(int i = 0;i<this->onValueUpdates.length();i++){
    this->onValueUpdates.get(i)(newValue);
   }
}
#endif
