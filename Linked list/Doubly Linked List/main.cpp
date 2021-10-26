#include <bits/stdc++.h>
#include "DoublyLinkedList.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
    dList<int> l;
    l.push_front(5); // 5
    l.push_front(6); // 6 5
    l.push_front(7); // 7 6 5
    l.push_back(8);  // 7 6 5 8
    l.push_back(10); // 7 6 5 8 10
    l.push_back(12); // 7 6 5 8 10 12
    l.print();
    l.insert(3, -5);
    l.print();
    cout << "pop " << l.pop_front() << " out of list!" << endl; // 6 5 -5 8 10 12
    l.print();
    cout << "pop " << l.pop_back() << " out of list!" << endl; // 6 5 -5 8 10
    l.print();
    cout << "erase " << l.erase(2) << " out of list!" << endl; // 6 5 -5 10
    l.print();
    for (dList<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
