#include <bits/stdc++.h>
#include "nStackLib.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
    nStackLib<int> s;
    s.push(1);
    cout << s.top() << endl;
    s.push(2);
    cout << s.top() << endl;
    s.push(3);
    cout << s.top() << endl;
    s.push(4);
    cout << s.top() << endl;
    s.push(5);
    cout << s.top() << endl;
    while (s.empty())
    {
        cout << s.pop() << " ";
    }
    cout << endl;
    return 0;
}
