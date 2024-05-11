#include <iostream>
#include <vector>

using namespace std;

class myset
{
private:
    vector<int> set_v;
    void recusion(int l, int r);

public:
    myset(vector<int> v);
    void show();
    vector<vector<myset>> huafen();
    ~myset();
};

void myset::show()
{
    for (int i = 0; i < set_v.size(); i++)
    {
        cout << set_v[i] << ' ';
    }
    cout << '\n';
}

myset::myset(vector<int> v) : set_v(v)
{
}

vector<vector<myset>> myset::huafen()
{
}

myset::~myset()
{
}

int main(int argc, char *argv[])
{

    return 0;
}