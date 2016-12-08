#ifndef _INPUTSOURCE_H
#define _INPUTSOURCE_H
#include "Async.h";
typedef void (*valueCallback)(int);
class InputSource : public Async{
  Array<valueCallback> valueChangeCB;
  public:
  InputSource(){
    
  }
  virtual void check() = 0;
  protected:
   void forAllValueChanged(int val){
    for(int i = 0;i< valueChangeCB.length();i++){
      valueChangeCB.get(i)(val);
    }
   }
 
  public:
  void onValueChanged(valueCallback cb){
    valueChangeCB.add(cb);
  }
};
class AnalogInputSource : public InputSource{
  int value = 0;
  const int pinNumber;
  public:
  AnalogInputSource(int analogPinNumber):pinNumber(analogPinNumber){
 
  }
  void check(){
    int newvalue = analogRead(pinNumber);
    if(newvalue != value) {
      newvalue = value;
      forAllValueChanged(newvalue);
    }
  }
};
class DigitalInputSource : public InputSource{
  boolean value = 0;
  int pinNumber = 0;
  public:
  DigitalInputSource(int digitalPin):pinNumber(digitalPin){
    
  }
  void check(){
    boolean newvalue = digitalRead(pinNumber);
    if(newvalue != value) {
      newvalue = value;
      forAllValueChanged(newvalue);
    }
  }
};
#endif
