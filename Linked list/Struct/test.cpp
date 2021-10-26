#include <bits/stdc++.h>
using namespace std;
void fun(int **p)
{
    int q = 10;
    *p = &q;
    cout << **p << endl; //(2) - 10
}

int main()
{
    int r = 20;
    int *p = &r;
    cout << *p << endl; //(1) - 20
    fun(&p);
    cout << *p << endl; //(3) - 20
    return 0;
}