#include <bits/stdc++.h>
using namespace std;
int x = 5;
int &fun(int &a)
{
    return a;
}
int main(int argc, char const *argv[])
{
    int a = 5;
    int &b = a;
    int x;
    x = b;
    return 0;
}
