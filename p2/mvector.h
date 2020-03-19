//
// Created by er on 2020/3/15.
//

#ifndef P2_MVECTOR_H
#define P2_MVECTOR_H

#include <iostream>
using namespace std;
#define DEFAULT_CAPACITY  3

//非伯纳切 实现方法
class Fib{
private:
    int i=0,j=1;
    int _n;
public:
    Fib(int n):_n(n){
       next();
        }

   int next() {
        if(_n==1||_n==2)
        return 1;


       for (int k = 1; k < _n; k++) {
           j = j + i;
           i = j - i;
       }
       return j;
   }
    int prev(){
        i=j-i;
        j=j-i;
        return j;
    }

    int get(){
        return j;
    }
};

//产生不大于n  的非伯纳切数
class Fib2 { //Fibonacci数列类
    private:
      int f, g; //f = fib(k - 1), g = fib(k)。均为int型，很快就会数值溢出
   public:
       Fib2 ( int n ) //初始化为不小于n的最小Fibonacci项
      { f = 1; g = 0; while ( g < n ) next(); } //fib(-1), fib(0)，O(log_phi(n))时间
     int get()  { return g; } //获取当前Fibonacci项，O(1)时间
     int next() { g += f; f = g - f; return g; }
   int prev() { f = g - f; g -= f; return g; }
   };
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
    //重载[]运算符
    mvector& operator[](int i){return _elem[i];}
    const mvector& operator[](int i )const{return  _elem[i];}
    //重载 = 运算符
    mvector& operator=(mvector& v){
        if(_elem) delete []_elem;
        CopyFrom(v,0,_size);
        return *this;
    };



    ~mvector() {
        delete [] _elem;
    }

    int  size()const{return _size;}
    int capacity()const{return _capacity;}
    bool empty()const{return !_size;}
protected:
    void CopyFrom(T const *A, int lo,int hi);//拷贝
    void expand();//检测并扩容
    void shrink(); //检测并删除多余容量
    int insert(int r, const T &data);//插入
    int remove(int lo,int hi);//删除
    T remove(int r);//删除单个元素，返回被删除的元素
    int find(T const &data,int lo,int hi)const ;//无序查找
    int deduplicate();//无序向量去重
    int uniquify01();//低效有序向量去重
    int uniquify02();//高效有序向量去重

    int binsearchA(T &data,int lo,int hi);
    int binsearchB(T &data,int lo,int hi);
    int binsearchC(T &data,int lo,int hi);
    int fibsearch(T &data,int lo,int hi);

    void bubbleSort(int lo,int hi);

    template <class VST>
    void traverse(VST &v);

    int disorted();
private:
   // int rank;
    int _size;
    int _capacity;
    T* _elem;

};


#endif //P2_MVECTOR_H
