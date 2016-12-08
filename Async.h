#ifndef _ASYNC_H
#define _ASYNC_H
#include "Arduino.h";
#include "Array.h";

typedef void (*callback)();
class Async{
  private:
  protected:
  public:
   static Array<Async*>* a;
   static void checkAll();
   Async();
   virtual void check(){}
};
Array<Async*>* Async::a = new Array<Async*>(); 

Async::Async(){
  Async::a->add(this);
}
void Async::checkAll(){
     for(int i = 0;i<Async::a->length();i++)
     {
      Async* obj = Async::a->get(i);
      obj->check();
     }
 
}
#endif
