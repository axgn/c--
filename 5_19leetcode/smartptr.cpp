#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> ptr = make_shared<int>(5);
    shared_ptr<int> ptrone = make_shared<int>(6);
    shared_ptr<int> ptr2 = ptr;
    shared_ptr<int> ptr3 = ptr;
    for (int i = 0; i < 5; i++)
    {
        shared_ptr<int> ptr4 = ptr3;
        cout << ptr << ' '
             << ptr2 << ' '
             << ptr3 << ' '
             << ptr4 << '\n';
        cout << ptr4.use_count() << '\n';
    }
    cout << ptr.use_count() << '\n';
    cout << boolalpha << (ptr2 > ptr);
    return 0;
}