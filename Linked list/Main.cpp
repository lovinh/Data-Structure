#include <iostream>
#include "LinkedList.cpp"
// #include "LinkedListStruct.cpp"
// #include "Node.cpp"
using namespace std;
#include <list>
int main(int argc, char const *argv[])
{
    // sNode<int> *A;
    // A = NULL;
    // cout << "List's state (1 - empty; 0 - not - empty): " << empty(A) << endl;
    // push_front(&A, 3);     // 3
    // push_front(&A, 4);     // 4 3
    // push_front(&A, 5);     // 5 4 3
    // push_front(&A, 6);     // 6 5 4 3
    // push_back<int>(&A, 7); // 6 5 4 3 7
    // insert(&A, 8, 0);      // 8 6 5 4 3 7
    // insert(&A, 9, 3);      // 8 6 5 9 4 3 7
    // insert(&A, -1, 6);     // 8 6 5 9 4 3 -1 7
    // insert(&A, 3, 20);     // 8 6 5 9 4 3 -1 7 0
    // erase(&A, 4);          // 8 6 5 9 3 -1 7 0
    // erase(&A, 0);          // 6 5 9 3 -1 7 0
    // printList(A);
    // cout << "First node is " << front(A) << endl;
    // cout << "Last node is " << back(A) << endl;
    // // for (sNode<int> *it = A; it != NULL; it = it->next)
    // // {
    // //     cout << it->data << " ";
    // // }
    // cout << "Reverse list! New list is ";
    // Reverse(&A);
    // // printList(A);
    // Print(A);
    // cList<int> l;
    // l.push_front(1); // 1
    // l.push_front(2); // 2 1
    // l.push_front(3); // 3 2 1
    // l.push_back(4);  // 3 2 1 4
    // cout << l.front() << endl;
    // cout << l.back() << endl;
    // cList<int> l1(5, 10);
    // cout << l1.front() << "\t" << l1.back() << "\t" << l1.size() << endl;
    // l.insert(9, 2); // 3 2 9 1 4
    // cout << l.pop_back() << endl;
    // l.erase(1);
    // l.printList();
    // for (cList<int>::iterator it = l.begin(); it != l.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;
    int arr[] = {1, 2, 2, 2, 3, 4, 4, 5};
    cList<int> l2(arr, 8);
    for (cList<int>::iterator it = l2.begin(); it != l2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << l2.front() << "\t" << l2.back() << endl;
    cList<int> l3;
    l3 = l2;
    for (cList<int>::iterator it = l3.begin(); it != l3.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (cList<int>::iterator it = l2.begin(); it != l2.end(); it++)
    {
        *it += 1;
        cout << *it << " ";
    }
    cout << endl;
    for (cList<int>::iterator it = l3.begin(); it != l3.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
