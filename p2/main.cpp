#include <iostream>
#include "cstdio"
#include "mvector.cpp"
using namespace std;

int main() {

    mvector<int> Vector(3,3,1);
    cout << Vector.capacity()<< endl;
    // cout << Vector;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
