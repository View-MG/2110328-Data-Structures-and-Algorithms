#include <iostream>
#include "list.h"

using namespace std;
int main()
{
    CP::list<int> x, a, b;
    x.push_back(1);
    x.push_back(7);
    x.push_back(9);
    x.push_back(10);
    x.push_back(2);
    x.push_back(6);
    x.push_back(3);

    a.push_back(1);
    a.push_back(2);

    b.push_back(3);
    b.push_back(4);
    b.push_back(5);
    x.splitList(a, b);
    std::cout<<"x is"<<std::endl;
    x.print();
    std::cout<<"a is"<<std::endl;
    a.print();
    cout<<"b is"<<endl;
    b.print();
    return 0;
}
