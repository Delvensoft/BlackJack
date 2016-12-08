#ifndef _TIMER_H
#define _TIMER_H
#include "Async.h";
class Interval:public Async{
  
  protected:
  int startTime = -1;
  int delayTime = 0;
  Array<callback> timeouts;

  public:
  Interval(unsigned int delay){
      delayTime = delay;
  }
  void setInterval(unsigned int delay){
    delayTime = delay;
  }
  void stop(){
    setInterval(0);
  }
  void start(){
    startTime = millis();
  }
  void check()
  {
    if(startTime >= 0){
     if(millis() - startTime > delayTime)
     {
       for(int i = 0;i<timeouts.length();i++){
        timeouts.get(i)();
       }
       startTime = millis();
     }
    }
  }
  void onTimeout(callback timeout)
  {
    timeouts.add(timeout);
   }
   
};

class Timeout:public Interval{
  Timeout(int delay = 1000):Interval(delay){
    
  }
 void check(){
  if(startTime >= 0){
     if(millis() - startTime > delayTime)
     {
       for(int i = 0;i<timeouts.length();i++){
        timeouts.get(i)();
       }
       startTime = -1;
     }
    }
 }
};
#endif
