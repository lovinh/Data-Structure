#include <bits/stdc++.h>
#include "StackLib.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
    StackLib<int> s;
    s.push(1); // 1
    s.push(2); // 1 2
    s.push(3); // 1 2 3
    s.push(4); // 1 2 3 4
    s.push(5); // 1 2 3 4 5
    cout << s.top() << endl;
    int len = s.size();
    while (len--)
    {
        cout << s.pop() << " ";
    }
    cout << endl;
    return 0;
}
