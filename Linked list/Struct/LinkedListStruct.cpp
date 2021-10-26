#ifndef __LinkedListStruct_cpp
#define __LinkedListStruct_cpp
#include <iostream>
using namespace std;
template <class T>
struct sNode // Một node
{
    T data;
    sNode<T> *next;
};
template <class T>
sNode<T> *init(T data = 0, sNode<T> *node = NULL)
{
    sNode<T> *nNode = new sNode<T>;
    nNode->data = data;
    nNode->next = node;
    return nNode;
}
// Modify - nang cap list
template <class T>
void push_front(sNode<T> **head, sNode<T> **tail, T data)
{
    sNode<T> *nNode = new sNode<T>;
    nNode->data = data;
    nNode->next = NULL;
    if (empty(*head))
    {
        *head = *tail = nNode;
    }
    else
    {
        nNode->next = *head;
        *head = nNode;
    }
}
template <class T>
void push_back(sNode<T> **head, sNode<T> **tail, T data)
{
    sNode<T> *nNode = new sNode<T>;
    nNode->data = data;
    nNode->next = NULL;
    if (empty(*head))
    {
        *head = *tail = nNode;
    }
    else
    {
        (*tail)->next = nNode;
        (*tail) = (*tail)->next;
    }
}
template <class T>
void insert(sNode<T> **head, sNode<T> **tail, int index, T data)
{
    if (index == 0)
    {
        push_front(head, tail, data);
        return; // Return để kết thúc hàm.
    }
    if (index == size(*head))
    {
        push_back(head, tail, data);
        return;
    }
    if (index > size(*head))
    {
        cout << "void insert(sNode<T> **head, sNode<T> **tail, int index, T data): Index khong ton tai!" << endl;
        return;
    }
    sNode<T> *nNode = new sNode<T>;
    nNode->data = data;
    nNode->next = NULL;
    // Tìm vị trí để chèn
    sNode<T> *it = *head;
    for (int i = 0; i < index - 1; i++)
    {
        it = it->next;
    }
    nNode->next = it->next;
    it->next = nNode;
}
template <class T>
bool empty(sNode<T> *head)
{
    return (head == NULL);
}

template <class T>
int size(sNode<T> *head)
{
    int count = 0;
    sNode<T> *it = head;
    while (it != NULL)
    {
        count++;
        it = it->next;
    }
    return count;
}

template <class T>
void print(sNode<T> *head)
{
    cout << "List is: ";
    sNode<T> *it = head;
    while (it != NULL)
    {
        cout << it->data << " ";
        it = it->next;
    }
    cout << endl;
}
#endif