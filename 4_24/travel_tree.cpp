#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int i = 0;

struct Bitree
{
    char data = 0;
    Bitree *lchild = nullptr;
    Bitree *rchild = nullptr;
};

void creatBi(Bitree *Troot, string s)
{
    if (Troot != nullptr)
        Troot->data = s[i];
    if (s[++i] != '#')
    {
        Troot->lchild = new Bitree;
        creatBi(Troot->lchild, s);
    }
    if (s[++i] != '#')
    {
        Troot->rchild = new Bitree;
        creatBi(Troot->rchild, s);
    }
}

void inordedtravel(Bitree *T)
{
    if (T)
    {
        inordedtravel(T->lchild);
        cout << T->data << ' ';
        inordedtravel(T->rchild);
    }
}

void preordedtravel(Bitree *T)
{
    if (T)
    {
        cout << T->data << ' ';
        preordedtravel(T->lchild);
        preordedtravel(T->rchild);
    }
}

void backordedtravel(Bitree *T)
{
    static int cnt = 0;
    if (T)
    {
        backordedtravel(T->lchild);
        backordedtravel(T->rchild);
        cout << T->data << ' ';
        cnt++;
        cout << cnt << ' ';
    }
}

void inordedtravel2(Bitree *T)
{
    stack<Bitree *> st;
    Bitree *temp;
    while (!st.empty() || T)
    {
        if (T)
        {
            st.push(T);
            T = T->lchild;
        }
        else
        {
            T = st.top();
            st.pop();
            if (T->rchild == nullptr || T->rchild == temp)
            {
                temp = T;
                cout << T->data << ' ';
                T = nullptr;
            }
            else
            {
                st.push(T);
                T = T->rchild;
            }
        }
    }
}

void Sequence_travel(Bitree *T)
{
    deque<Bitree *> temp;
    temp.push_back(T);
    while (!temp.empty())
    {
        T = temp.front();
        temp.pop_front();
        cout << T->data << ' ';
        if (T->lchild)
            temp.push_back(T->lchild);
        if (T->rchild)
            temp.push_back(T->rchild);
    }
}

int main()
{
    string s = "abc##de#g##f###";
    Bitree *tree = new Bitree;
    creatBi(tree, s);
    inordedtravel(tree);
    cout << '\n';
    preordedtravel(tree);
    cout << '\n';
    backordedtravel(tree);
    cout << '\n';
    Sequence_travel(tree);
    cout << '\n';
    inordedtravel2(tree);
    return 0;
}#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int i = 0;

struct Bitree
{
    char data = 0;
    Bitree *lchild = nullptr;
    Bitree *rchild = nullptr;
};

void creatBi(Bitree *Troot, string s)
{
    if (Troot != nullptr)
        Troot->data = s[i];
    if (s[++i] != '#')
    {
        Troot->lchild = new Bitree;
        creatBi(Troot->lchild, s);
    }
    if (s[++i] != '#')
    {
        Troot->rchild = new Bitree;
        creatBi(Troot->rchild, s);
    }
}

void inordedtravel(Bitree *T)
{
    if (T)
    {
        inordedtravel(T->lchild);
        cout << T->data << ' ';
        inordedtravel(T->rchild);
    }
}

void preordedtravel(Bitree *T)
{
    if (T)
    {
        cout << T->data << ' ';
        preordedtravel(T->lchild);
        preordedtravel(T->rchild);
    }
}

void backordedtravel(Bitree *T)
{
    if (T)
    {
        backordedtravel(T->lchild);
        backordedtravel(T->rchild);
        cout << T->data << ' ';
    }
}

void inordedtravel2(Bitree *T)
{
    stack<Bitree *> st;
    Bitree *temp;
    while (!st.empty() || T)
    {
        if (T)
        {
            st.push(T);
            T = T->lchild;
        }
        else
        {
            T = st.top();
            st.pop();
            if (T->rchild == nullptr || T->rchild == temp)
            {
                temp = T;
                cout << T->data << ' ';
                T = nullptr;
            }
            else
            {
                st.push(T);
                T = T->rchild;
            }
        }
    }
}

void Sequence_travel(Bitree *T)
{
    queue<Bitree *> temp;
    temp.push(T);
    while (!temp.empty())
    {
        T = temp.front();
        temp.pop();
        cout << T->data << ' ';
        if (T->lchild)
            temp.push(T->lchild);
        if (T->rchild)
            temp.push(T->rchild);
    }
}

int main()
{
    string s = "abc##de#g##f###";
    Bitree *tree = new Bitree;
    creatBi(tree, s);
    inordedtravel(tree);
    cout << '\n';
    preordedtravel(tree);
    cout << '\n';
    backordedtravel(tree);
    cout << '\n';
    Sequence_travel(tree);
    cout << '\n';
    inordedtravel2(tree);
    return 0;
}