#ifndef _OUTPUTSOURCE_H
#define _OUTPUTSOURCE_H
class OutputSource{
  public:
 virtual void write(int val) = 0;
};
class DigitalOutputSource:public OutputSource{
  protected:
  const int pinNumber;
  public:
  DigitalOutputSource(int pin):pinNumber(pin){
    pinMode(OUTPUT,pin);
  }
  void write(int value){
    digitalWrite(pinNumber,value == 0 ? LOW : HIGH);
  }
  int pin(){
    return pinNumber;
  }
};
class PWMOutputSource : public DigitalOutputSource{
  public:
  PWMOutputSource(int pin):DigitalOutputSource(pin){
    
  }
  void write(int value){
   analogWrite(pinNumber,value);
  }
};
#endif
