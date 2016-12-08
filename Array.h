#ifndef _ARRAY_H
#define _ARRAY_H
#include "Arduino.h"
template <typename T> 
class Array{
     private:
     int size = 0;
     void resize(int size);
     T* a = NULL;
    public:
     Array(int length = 0);
     Array(Array& other);
     ~Array();
     T get(const int index);
     void add(const T);
     void set(const int,const T);
     int indexOf(const T);
     void foreach(void (*)(T,int));
     void remove(const int);
     int length();
};
template <typename T>
Array<T>::Array(int length){
    a = (T *) malloc(sizeof(T) * length);
    size = length;
}
template <typename T>
Array<T>::Array(Array& other){
    this->size = other.size;
    this->a = other.a;
}
template <typename T>
void Array<T>::resize(int length){
a = (T*) realloc(a,sizeof (T) * length);
size = length;
}
template <typename T>
Array<T>::~Array(){
    free(a);
    a = NULL;
}
template <typename T>
T Array<T>::get(const int index){
    return a[index];
}
template <typename T>
 void Array<T>::add(const  T e){
    resize(size+1);
    a[size-1] = e;
}
template <typename T>
void Array<T>::set(const int index,const  T e){
    if(index < size && index > -1)  a[index] = e;
}
template <typename T>
int Array<T>::indexOf(const T e){
   for(int i = 0;i<this->size;i++){
       if(a[i] == e){
           return i;
       }
   }
   return -1;
}
template <typename T>
void Array<T>::foreach(void (*callback)(T,int)){
    for(int i = 0;i<size;i++){
        callback(a[i],i);
    }
}
template <typename T>
void Array<T>::remove(const int index){
    for(int i = index;i<size;i++){
       a[i] = a[i+1];
    }
    resize(size-1);
}
template <typename T>
int Array<T>::length(){
    return size;
}
#endif 
