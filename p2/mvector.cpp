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

//删除区间元素
template<class T>
int mvector<T>::remove(int lo,int hi){
    if(hi == lo)return 0;
    while(hi<_size){
        _elem[lo++]=_elem[hi++];
    }
    _size =lo;
    shrink();
    return hi-lo;

}
//删除单个元素
template <class T>
T mvector<T>::remove(int r){
    T elem = _elem[r];
    remove(r,r+1);
    return elem;
}

//无序向量查找
template <class T>
int mvector<T>::find(const T &data, int lo, int hi) const {
    while((lo<hi--)&&(data!=_elem[hi]));
    return hi;
}

//无序向量去重
template <class T>
int mvector<T>::deduplicate(){
    int i =1 ;
    int old_size = _size;
    while(i<_size){
        (find(_elem[i],0,_size)<0)? i++ : remove(i);
    }

    return old_size - _size;
}

//无序向量利用函数对象机制遍历 ？？？？？？？？？？？？？？？？？？？？还不太懂
template <typename T> template <typename VST>
void mvector<T>::traverse(VST &v){
    for(int i=0;i<_size;i++){
        v(_elem[i]);
    }
}

//判断是不是有序向量
template <class T>
int mvector<T>::disorted(){
    int n=0;
    int i = 0;
    while(i<_size){
        if(_elem[i] < _elem[i+1]){
            n++;
        }
        i++;
    }
    return n;
}

template <class T>
int mvector<T>::uniquify01(){
    int i =1;
    int old = _size;
    while(i<_size){
        if(_elem[i]==_elem[i-1]){
            remove(i);
        } else{
            i++;
        }
    }
    return old-_size;
}

template <class T>
int mvector<T>::uniquify02(){
    int old = _size;
    int i=0,j=1;
    while(j<_size){
        if(_elem[i]!=_elem[j]){
            _elem[++i]=_elem[j++];
        }
    }
    return old-_size;
}

//二分查找实现A版本
template <class  T>
int mvector<T>::binsearchA(T &data,int lo,int hi){

    while(lo<hi){
       int mid = (hi+lo)>>1;
        if(data<_elem[mid]){
            hi = mid;
        } else if(data > _elem[mid]){
            lo = mid +1;
        } else{
            return mid;
        }
    }
    return -1;
}

template <class  T>
int mvector<T>::binsearchB(T &data,int lo,int hi){
    while(hi-lo>1){
        int mid = (lo+hi)>>1;
        (data<_elem[mid])?hi=mid:lo=mid;
    }
    return (_elem[lo]==data)?lo:-1;
}

template <class  T>
int mvector<T>::binsearchC(T &data,int lo,int hi){
    while (lo<hi){
        int mid = (lo+hi)>>1;
        (data < _elem)?hi=mid:lo=mid+1;
    }
    return lo-1;
}

template <class T>
int mvector<T>::fibsearch(T &data,int lo,int hi){

    for(Fib2 fib(hi-lo);hi<lo;){
        while (hi-lo<fib.get()) fib.prev();//我觉的就是起个判断的作用
        int mid =lo+fib.get()-1;
        if(data < _elem[mid]){
            hi = mid;
        }
       else if(data > _elem[mid]){
            lo =mid+1;
       }
       else{
            return mid;
       }


        return -1;//查找失败
    }
    return 0;

}

template <class T>
void mvector<T>::bubbleSort(int lo,int hi){

}