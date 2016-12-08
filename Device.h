#ifndef _DEVICE_H
#define _DEVICE_H
#include "Arduino.h";
#include "OutputSource.h";
 enum DeviceMode {
     IN, OUT, IN_PULLUP
 };
 class Device{
 
    public:
     Device(){
         
     }
    
 };
 class OutputDevice:public Device{
  OutputSource* source;
  int val = 0;
  public:
  OutputDevice(){
    
  }
  OutputDevice(OutputSource* source){
    setOutput(source);
  }
  void setOutput(OutputSource* source){
    this->source = source;
  }
  void write(int val)
  {
    this->val = val;
    this->source->write(val);
  }
  void on(int val = 255){
    write(val);
  }
  void off(){
    write(0);
  }
  void toggle(){
   val == 0 ? on() : off();
  }
  };
 typedef OutputDevice Led;
#endif
