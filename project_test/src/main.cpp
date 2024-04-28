#include <iostream>
#include<cstring>
#include<string>
#include "one.h"
template<typename T> 
T print(T a,T b)
{
    std::cout << a << b;
    return a + b;
}

int main()
{
    std::string s1 = "jjjjj";
    std::string s2 = "kkkkk";
    std::string s3 = "aaaaa";
    print(print(s1, s2),s3);
    return 0;
}

int one()
{
    return 1;
}