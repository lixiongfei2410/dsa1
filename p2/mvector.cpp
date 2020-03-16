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

//扩容
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

//删除空余容量 小于容量的四分之一
template<class T>
void mvector<T>::shrink(){
    if(_capacity < DEFAULT_CAPACITY*2) return ;
    if(_size *4 >_capacity) return;
    T *old = _elem;
    _elem = new T[_capacity/2];
    for(int i=0;i!=_size;i++){
        _elem[i] = old[i];
    }
    delete []old;

}

template<class T>
int mvector<T>::insert(int r, const T &data){
    expand();
    for(int i=_size;i>r;i--){
        _elem[i] = _elem[i-1];
    }
    _elem[r]  = data;
    _size ++; //更新数组大小
    return r;//返回插入位置
}

template<class T>
int mvector<T>::remove(int lo,int hi){
    if(hi == lo)return 0;
    while(hi<_size){
        _elem[lo++]=_elem[hi++];
    }
    _size =lo;
    return hi-lo;

}
template <class T>
T mvector<T>::remove(int r){
    T elem = _elem[r];
    remove(r,r+1);
    return elem;
}

template <class T>
int mvector<T>::find(const T &data, int lo, int hi) const {
    while((lo<hi--)&&(data!=_elem[hi]));
    return hi;
}


