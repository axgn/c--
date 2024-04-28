#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <chrono>
#include <iomanip>
using namespace std;

int main()
{
    int pos = 0;
    int cnt = 0;
    int temp = 0;
    string_view s = "abcaabcaab";
    string_view str = "aab";
    const auto start{std::chrono::steady_clock::now()};
    if ((temp = s.find(str, pos)) != string::npos)
    {
        pos = temp;
        cnt++;
        pos++;
    }
    while (pos != string::npos)
    {
        pos = s.find(str, pos);
        if (pos != string::npos)
        {
            cnt++;
            pos++;
        }
    }
    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds = end - start;
    auto duration = chrono::duration_cast<chrono::milliseconds>(elapsed_seconds);
    std::cout << std::fixed << std::setprecision(9) << std::left;
    cout << duration.count() << "\n";
    cout << temp << ' ' << cnt;
    return 0;
}
