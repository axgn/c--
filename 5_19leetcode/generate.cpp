#include <random>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    random_device rd;
    ofstream f("one.txt");
    minstd_rand0 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    uniform_int_distribution<> dis2(0, 25);
    for (int i = 0; i < 100; i++)
    {
        int ram = dis(gen);
        string s;
        for (int i = 0; i < ram; i++)
        {
            s.push_back('a' + dis2(gen));
        }
        f << s << '\n';
    }
    return 0;
}