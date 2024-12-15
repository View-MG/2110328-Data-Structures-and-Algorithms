#include <iostream>
#include "student.h"
using namespace std;

void test1() {
    vector<int> v1 = {41, 43, 11, 12, 19, 8, 28, 14, 26, 48, 49, 50, 16, 27, 52, 30, 45, 10, 42, 36, 23, 46, 38, 3, 0, 54, 44, 24, 25, 9, 29, 40};
    vector<int> v2 = {16, 53, 21, 20, 44, 30, 36, 12, 26, 10, 7, 32, 15, 49, 52, 55, 33, 37, 29, 28, 3, 35, 11, 54};
    vector<int> v = Union(v1, v2);
    for (auto& x:v) {
        cout<<x<<" ";
    }
    cout<<endl;
}

void test2() {
    vector<int> v1 = {41, 43, 11, 12, 19, 8, 28, 14, 26, 48, 49, 50, 16, 27, 52, 30, 45, 10, 42, 36, 23, 46, 38, 3, 0, 54, 44, 24, 25, 9, 29, 40};
    vector<int> v2 = {16, 53, 21, 20, 44, 30, 36, 12, 26, 10, 7, 32, 15, 49, 52, 55, 33, 37, 29, 28, 3, 35, 11, 54};
    vector<int> v = Intersect(v1, v2);
    for (auto& x:v) {
        cout<<x<<" ";
    }
    cout<<endl;
}
int main()
{
    test1();
    test2();
    return 0;
}
