#ifndef __nStackLib_cpp
#define __nStackLib_cpp
#include <stdio.h>
#include <stdlib.h>
template <class T>
class Node
{
private:
    T _data;
    Node *_next;

public:
    Node()
    {
        _next = nullptr;
    }
    Node(const T &data, Node<T> *next)
    {
        _data = data;
        _next = next;
    }
    T &getData()
    {
        return this->_data;
    }
    Node<T> *getNext()
    {
        return this->_next;
    }
    void setData(const T &data)
    {
        _data = data;
    }
    void setNext(Node<T> *next)
    {
        _next = next;
    }
};
template <class T>
class nStackLib
{
private:
    Node<T> *_head;
    unsigned int _size;

public:
    nStackLib()
    {
        _head = nullptr;
        _size = 0;
    };
    void push(const T &data)
    {
        Node<T> *item = new Node<T>(data, nullptr);
        if (_head == nullptr)
        {
            _head = item;
            return;
        }
        item->setNext(_head);
        _head = item;
    }
    T pop()
    {
        Node<T> *dItem;
        T returnData = _head->getData();
        dItem = _head;
        if (_head == nullptr)
        {
            printf("Error: Cannot pop out item in an empty stack!");
            exit(-1);
        }
        _head = _head->getNext();
        delete dItem;
        return returnData;
    }
    T &top()
    {
        if (_head == nullptr)
        {
            printf("Error: stack is empty!");
            exit(-1);
        }
        return _head->getData();
    }
    unsigned int size() const
    {
        return _size;
    }
    bool empty() const
    {
        return (_size == 0);
    }
    bool search(const T &data)
    {
        Node<T> *it = _head;
        while (it != nullptr)
        {
            if (it->getData() == data)
            {
                return true;
            }
            it = it->getNext();
        }
        return false;
    }
    ~nStackLib()
    {
        Node<T> *dNode = _head;
        if (_head != nullptr)
        {
            _head = _head->getNext();
            delete dNode;
        }
    }
};
#endif