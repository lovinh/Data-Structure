#include <bits/stdc++.h>
#include "aQueue.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
    aQueue<int> q;
    q.push(1);
    cout << q.front() << " " << q.back() << endl;
    q.push(2);
    cout << q.front() << " " << q.back() << endl;
    q.push(3);
    cout << q.front() << " " << q.back() << endl;
    q.push(4);
    cout << q.front() << " " << q.back() << endl;
    q.push(5);
    cout << q.front() << " " << q.back() << endl;
    while (!q.empty())
    {
        cout << q.pop() << " ";
    }
    q.pop();
    return 0;
}
