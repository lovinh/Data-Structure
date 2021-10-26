#include <iostream>
#include <vector>
#include "VectorLibrary.cpp"
using namespace std;
void printOutReverse(VectorLibrary<int> &v)
{
    for (VectorLibrary<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
    cout << "size = " << v.size() << "\tcapacity = " << v.capacity() << endl;
}

void printOut(VectorLibrary<int> &v)
{
    for (VectorLibrary<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    cout << "size = " << v.size() << "\tcapacity = " << v.capacity() << endl;
}
int main()
{
    VectorLibrary<int> v1, w;
    int a = 19;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);
    v1.push_back(10);
    v1.push_back(12);
    v1.push_back(13);
    v1.push_back(14);
    v1.push_back(15);
    v1.push_back(16);
    v1.push_back(17);
    v1.push_back(18);
    v1.push_back(a);
    printOutReverse(v1);
    v1.erase(3, 8);
    printOut(v1);
    cout << v1.at(1);
}
