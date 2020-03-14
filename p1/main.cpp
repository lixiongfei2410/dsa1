#include <iostream>
using namespace std;

// 递归形式
long double fb1(int n)
{
    if(n<1)
    {
        return -1;
    }
    if(n==1||n==2)
    {
        return 1;
    }

    return fb1(n-1)+fb1(n-2);
}
//数组形式存储，动态规划 时间复杂度O(n),空间复杂度O(n)
long double fb2(int n )
{
    if(n<1)
        return -1;
    int *p =new int[n+1];
    p[1] = p[2] =1;
    for(int i=3;i<=n;i++)
    {
        p[i]=p[i-1]+p[i-2];
    }
    long double res = p[n];
    delete []p;
    return res;

}

//时间复杂度O(n),空间复杂度O(1)
long double fb3(int n)
{
    if(n<1)
        return -1;
    long double s1,s2;
    s1 = s2 =1;
    for(int i=3;i<=n;i++)
    {
        s2 = s1 + s2;
        s1 = s2 -s1;
    }
    return s2;
}
int main() {

    long double result = fb1(20);
    cout << result << endl;

    long double result2 = fb2(20);
    cout << result2 << endl;

    long double result3 = fb2(20);
    cout << result3 << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
