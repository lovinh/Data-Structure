#ifndef __DoublyLinkedList_cpp
#define __DoublyLinkedList_cpp
#include <iostream>
#include "dNode.cpp"
using namespace std;
template <class T>
class _iterator
{
private:
    dNode<T> *_it;

public:
    _iterator()
    {
        _it = NULL;
    }
    _iterator(dNode<T> *o_it)
    {
        _it = o_it;
    }
    _iterator(const _iterator<T> &o_it)
    {
        _it = o_it._it;
    }
    _iterator &operator=(_iterator<T> &other)
    {
        this->_it = other._it;
        return (*this);
    }
    T &operator*()
    {
        return _it->getData();
    }
    bool operator==(const _iterator<T> &other)
    {
        return (_it == other._it);
    }
    bool operator!=(const _iterator<T> &other)
    {
        return (_it != other._it);
    }
    _iterator<T> operator++(int) //postfix
    {
        _it = _it->getNext();
        return (*this);
    }
    _iterator<T> operator++() //postfix
    {
        _iterator<T> temp;
        temp._it = _it;
        _it = _it->getNext();
        return temp;
    }
    _iterator<T> operator--(int)
    {
        _it = _it->getPrevious();
        return (*this);
    }
    _iterator<T> operator--()
    {
        _iterator<T> temp;
        temp._it = _it;
        _it = _it->getPrevious();
        return temp;
    }
};
template <class T>
class dList
{
private:
    dNode<T> *_head;
    dNode<T> *_tail;
    size_t _size;

public:
    dList()
    {
        _head = _tail = NULL;
        _size = 0;
    }
    dList(size_t numbers, const T &value = 0)
    {
        _head = _tail = NULL;
        _size = 0;
        while (numbers--)
            push_back(value);
    }
    dList(T *arr, size_t numbers)
    {
        _head = _tail = NULL;
        _size = 0;
        for (int i = 0; i < numbers; i++)
        {
            push_back(arr[i]);
        }
    }
    ~dList()
    {
        dNode<T> *it = _tail;
        while (it != NULL)
        {
            _tail = it->getPrevious();
            delete it;
            it = _tail;
        }
    }
    //Modify
    void push_back(const T &data)
    {
        dNode<T> *nNode = new dNode<T>();
        nNode->setData(data);
        nNode->setNext(NULL);
        nNode->setPrevious(NULL);
        if (empty())
        {
            _head = _tail = nNode;
            _size++;
            return;
        }
        _tail->setNext(nNode);
        nNode->setPrevious(_tail);
        _tail = nNode;
        _size++;
    }
    void push_front(const T &data)
    {
        dNode<T> *nNode = new dNode<T>();
        nNode->setData(data);
        nNode->setNext(NULL);
        nNode->setPrevious(NULL);
        if (empty())
        {
            _head = _tail = nNode;
            _size++;
            return;
        }
        nNode->setNext(_head);
        _head->setPrevious(nNode);
        _head = nNode;
        _size++;
    }
    void insert(size_t index, const T &data)
    {
        if (index == 0)
        {
            push_front(data);
            return;
        }
        if (index >= _size)
        {
            push_back(data);
            return;
        }
        dNode<T> *nNode = new dNode<T>();
        nNode->setData(data);
        nNode->setNext(NULL);
        nNode->setPrevious(NULL);
        if (empty())
        {
            _head = _tail = nNode;
            _size++;
            return;
        }
        dNode<T> *it = _head;
        for (size_t i = 0; i < index - 1; i++)
        {
            it = it->getNext();
        }
        nNode->setNext(it->getNext());
        nNode->setPrevious(it);
        (it->getNext())->setPrevious(nNode);
        it->setNext(nNode);
        _size++;
    }
    T pop_front()
    {
        T pop_data;
        if (!empty())
        {
            if (_size == 1)
            {
                pop_data = _head->getData();
                delete _head;
                _head = _tail = NULL;
                _size--;
            }
            else
            {
                pop_data = _head->getData();
                dNode<T> *d_Node = _head;
                _head = d_Node->getNext();
                _head->setPrevious(NULL);
                delete d_Node;
                _size--;
            }
        }
        return pop_data;
    }
    T pop_back()
    {
        T pop_data;
        if (!empty())
        {
            if (_size == 1)
            {
                pop_data = _tail->getData();
                _head = _tail = NULL;
                _size--;
            }
            else
            {
                pop_data = _tail->getData();
                dNode<T> *d_Node = _tail;
                _tail = d_Node->getPrevious();
                _tail->setNext(NULL);
                delete d_Node;
                _size--;
            }
        }
        return pop_data;
    }
    T erase(size_t index)
    {
        if (index >= _size)
            index = _size - 1;
        T pop_data;
        if (!empty())
        {
            if (_size == 1)
            {
                pop_data = _head->getData();
                _head = _tail = NULL;
                _size--;
            }
            else if (index == 0)
            {
                pop_data = pop_front();
            }
            else if (index == _size - 1)
            {
                pop_data = pop_back();
            }
            else
            {
                dNode<T> *d_Node = _head;
                for (int i = 0; i < index; i++)
                {
                    d_Node = d_Node->getNext();
                }
                pop_data = d_Node->getData();
                (d_Node->getPrevious())->setNext(d_Node->getNext());
                (d_Node->getNext())->setPrevious(d_Node->getPrevious());
                delete d_Node;
                _size--;
            }
        }
        return pop_data;
    }
    //Iterator
    typedef _iterator<T> iterator;
    iterator begin()
    {
        return iterator(_head);
    }
    iterator end()
    {
        return iterator(NULL);
    }
    void print()
    {
        dNode<T> *it = _head;
        cout << "List is ";
        while (it != NULL)
        {
            cout << it->getData() << " ";
            it = it->getNext();
        }
        cout << endl;
    }
    //Capacity
    bool empty()
    {
        return (_size == 0);
    }
    //Access
    T &front()
    {
        return _head->getData();
    }
    T &back()
    {
        return _tail->getData();
    }
};
#endif