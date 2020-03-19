#include <iostream>
#include <list>
#include <vector>
using namespace std;

//使用连表初始化数组
void test01(){
    list<int> l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);

    vector<int> v(l1.begin(),l1.end());
    for(vector<int>::iterator i=v.begin();i!=v.end();i++){
        cout << *i <<endl;
    }

}
int main() {

    test01();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
