#include "student.h"
#include <iostream>
#include <vector>
int main(){
    CP::pair<int,std::string> s1,s2;
    std::cin >> s1.first >> s1.second;
    std::cin >> s2.first >> s2.second;
    std::cout << (s1 >= s2);
}