#include <bits/stdc++.h>
#include "VectorLib.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
    VectorLib<int> v1; // v1 size = capacity = 10;
    v1.push_back(12);
    v1.push_back(10);
    v1.push_back(8);
    v1.push_back(9);
    // v1.print();
    // cout << v1.front() << endl;
    v1.insert(0, -2);
    // v1.print();
    v1.insert(2, -3);
    // v1.print();
    v1.push_front(15);
    v1.print();
    // cout << "pop " << v1.pop_back() << " out of vector!" << endl;
    // v1.print();
    // cout << "pop " << v1.pop_front() << " out of vector!" << endl;
    // v1.print();
    v1.erase(0);
    v1.print();
    for (VectorLib<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        // *it += 1;
        cout << *it << " ";
    }
    cout << endl;
    for (VectorLib<int>::rIterator rIt = v1.rbegin(); rIt != v1.rend(); rIt++)
    {
        cout << *rIt << " ";
    }
    cout << endl;
    cout << v1.at(v1.begin() + 2) << endl;
    return 0;
}
