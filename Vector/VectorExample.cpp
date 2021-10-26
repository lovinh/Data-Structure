#include <bits/stdc++.h>
using namespace std;
void printOut(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    vector<int> v1;
    vector<int> v4(10);
    vector<int> v2(5, 0);
    int arr[] = {1, 2, 3};
    vector<int> v3(arr, arr + 3);

    v3.pop_back();
    printOut(v3);
    v3.push_back(3);
    v3.push_back(4);
    v3.push_back(5);
    v3.push_back(6);
    v3.push_back(7);
    printOut(v3);
    // Iterator
    // cout << endl;
    // for (vector<int>::reverse_iterator it = v3.rbegin(); it != v3.rend(); it++)
    // {
    //     cout << *it << " ";
    // }
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    v4.pop_back();
    cout << "\nvector v4: " << endl;
    cout << "size: " << v4.size() << "\ncapacity: " << v4.capacity() << "\nmax size: " << v4.max_size();
    cout << "\nis empty: " << v4.empty() << endl;
    v4.push_back(1);
    cout << "\nvector v4: " << endl;
    cout << "size: " << v4.size() << "\ncapacity: " << v4.capacity() << "\nmax size: " << v4.max_size();
    cout << "\nis empty: " << v4.empty() << endl;
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);
    cout << "\nvector v4: " << endl;
    cout << "size: " << v4.size() << "\ncapacity: " << v4.capacity() << "\nmax size: " << v4.max_size();
    cout << "\nis empty: " << v4.empty() << endl;
}