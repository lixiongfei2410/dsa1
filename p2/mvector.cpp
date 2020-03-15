//
// Created by er on 2020/3/15.
//

#include "mvector.h"

//数据转移
template<class T>
void mvector<T>::CopyFrom(T const *A, int lo, int hi){
    _size = 0;
    _elem = new T[_capacity = (hi -lo )*2];
    while(lo < hi){
        _elem[_size++]=A[lo++];
    }
}

template <class T>
void mvector<T>::expand(){
    if(_size < _capacity) return;
    T *old = _elem;
    _elem = new T[_capacity * 2];
    for(int i=0;i<_size;i++){
        _elem[i]=old[i];
    }
    delete []old;



}