#include <bits/stdc++.h>
#include "LinkedListStruct.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
    sNode<int> *head = NULL;
    sNode<int> *tail = NULL;
    push_front(&head, &tail, 5);
    push_front(&head, &tail, 10);
    push_front(&head, &tail, 15);
    push_back(&head, &tail, 20); // 15 10 5 20
    // print(head);
    insert(&head, &tail, 2, 25); // 15 10 25 5 20
    insert(&head, &tail, 0, 24); // 24 15 10 25 5 20
    insert(&head, &tail, 6, 24); // 24 15 10 25 5 20 24
    insert(&head, &tail, 8, 24); // 24 15 10 25 5 20 24
    print(head);
    return 0;
}
