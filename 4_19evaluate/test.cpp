#include <iostream>

int main()
{
    int a = 3;
    int b = 5;
    int c = 6;

    // 按值来捕获
    auto func1 = [=]()
    { std::cout << ' ' << c << std::endl; };
    func1();

    // 按值来捕获
    auto func2 = [=](int a)
    { std::cout << a << " " << b << std::endl; };
    func2(c);

    // 按引用来捕获
    auto func3 = [&](int a)
    { std::cout << a << std::endl; a = 5; };
    func3(c);
    std::cout << c << std::endl;
    // 按引用来捕获
    auto func4 = [&]
    { std::cout << a << " " << b << std::endl; };
    func4();
}