#include <iostream>
#include <vector>

using namespace std;

class matrix
{
private:
    vector<vector<int>> v;
    size_t size;

public:
    matrix(vector<vector<int>> v);
    matrix Warshall();
    void show();
    ~matrix();
};

matrix::matrix(vector<vector<int>> v1) : v(v1), size(v1.size())
{
}

matrix matrix::Warshall()
{
    vector<vector<int>> res = v;
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            if (res[i][j] == 1)
            {
                for (int k = 0; k < size; k++)
                {

                    res[i][k] |= res[j][k];
                }
            }
        }
    }
    return matrix(res);
}

void matrix::show()
{
    for (auto &i : v)
    {
        for (auto &j : i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }
}

matrix::~matrix()
{
}

int main(int argc, char *argv[])
{
    matrix m1({{1, 1, 1}, {0, 0, 1}, {1, 0, 1}});
    m1.show();
    matrix res = m1.Warshall();
    res.show();
    return 0;
}