//
// Created by er on 2020/3/15.
//

#ifndef P2_MVECTOR_H
#define P2_MVECTOR_H


#define DEFAULT_CAPACITY  3
template <class T>
class mvector {
public:

    mvector(int c = DEFAULT_CAPACITY ,int size =0,T v =0){
        _elem = new T[_capacity = c ];
        for(int i = 0;i<size;i++){
            _elem[i] = v;
        }
        _size = 0;
    }
    //复制构造函数,整体向量复制
    mvector(mvector<T> const &v){
        CopyFrom(v,0,_size);
    }

    //向量部分拷贝
    mvector(mvector<T> const &v,int lo,int hi){
        CopyFrom(v,lo,hi);
    }
    //数组拷贝
    mvector(const T *A,int lo, int hi){
        CopyFrom(A,lo,hi);
    }
    ~mvector() {
        delete [] _elem;
    }

    int const size(){return _size;}
    int const capacity(){return _capacity;}
    bool empty(){return !_size;}
protected:
    void CopyFrom(T const *A, int lo,int hi);//拷贝
    void expand();//检测并扩容


private:
   // int rank;
    int _size;
    int _capacity;
    T* _elem;

};


#endif //P2_MVECTOR_H
