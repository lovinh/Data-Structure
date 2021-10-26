#ifndef __LinkedList_cpp
#define __LinkedList_cpp
#include "Node.cpp"
#include "iostream"
using namespace std;
template <class T>
class cIterator
{
private:
    cNode<T> *_it;

public:
    cIterator()
    {
        _it = NULL;
    }
    cIterator(cNode<T> *o_it)
    {
        _it = o_it;
    }
    cIterator &operator=(cIterator<T> o_it)
    {
        this->_it = o_it._it;
        return *this;
    }
    T &operator*()
    {
        return this->_it->getData();
    }
    bool operator==(cIterator<T> o_it)
    {
        return (_it == o_it._it);
    }
    bool operator!=(cIterator<T> o_it)
    {
        return (_it != o_it._it);
    }
    //postfix: i++, prefix: ++i
    cIterator<T> operator++(int)
    {
        cIterator<T> temp;
        temp._it = _it;
        _it = _it->getNext();
        return temp;
    }
    cIterator<T> operator++()
    {
        _it = _it->getNext();
        return *this;
    }
};
template <class T>
class cList
{
private:
    cNode<T> *_head;
    cNode<T> *_tail;
    size_t _size;

public:
    cList<T>()
    {
        _head = _tail = NULL;
        _size = 0;
    }
    cList<T>(size_t amount, T default_data)
    {
        _head = _tail = NULL;
        _size = 0;
        while (amount--)
        {
            push_back(default_data);
        }
    }
    cList<T>(T *arr, size_t size)
    {
        _head = _tail = NULL;
        _size = 0;
        int i = 0;
        while (size--)
        {
            push_back(arr[i]);
            i++;
        }
    }
    cList<T> &operator=(cList<T> &o_list)
    {
        _head = o_list._head;
        _tail = o_list._tail;
        _size = o_list._size;
        return *this;
    }
    //Modify
    void push_front(const T &data)
    {
        cNode<T> *nNode = new cNode<T>();
        nNode->setData(data);
        nNode->setNext(NULL);
        if (empty())
        {
            _head = nNode;
            _tail = nNode;
        }
        else
        {
            nNode->setNext(_head);
            _head = nNode;
        }
        _size++;
    }
    void push_back(const T &data)
    {
        cNode<T> *nNode = new cNode<T>();
        nNode->setData(data);
        nNode->setNext(NULL);
        if (empty())
        {
            _head = nNode;
            _tail = nNode;
        }
        else
        {
            _tail->setNext(nNode);
            _tail = nNode;
        }
        _size++;
    }
    void insert(const T &data, size_t index)
    {
        if (index > _size)
            index = _size;
        if (index == 0)
        {
            push_front(data);
            return;
        }
        if (index == _size)
        {
            push_back(data);
            return;
        }
        cNode<T> *nNode = new cNode<T>();
        nNode->setData(data);
        nNode->setNext(NULL);
        cNode<T> *it = _head;
        for (int i = 0; i < index - 1; i++)
        {
            it = it->getNext();
        }
        nNode->setNext(it->getNext());
        it->setNext(nNode);
        _size++;
    }
    T pop_front()
    {
        if (_size == 0)
        {
            return this->_head->getData();
        }
        cNode<T> *dNode = _head;
        if (_size == 1)
        {
            _head = _tail = NULL;
        }
        else
        {
            _head = _head->getNext();
            dNode->setNext(NULL);
        }
        T data_return = dNode->getData();
        delete dNode;
        _size--;
        return data_return;
    }
    T pop_back()
    {
        if (_size == 0)
            return this->_head->getData();
        cNode<T> *dNode = _tail;
        if (_size == 1)
        {
            _head = _tail = NULL;
        }
        else
        {
            cNode<T> *it = _head;
            while ((it->getNext())->getNext() != NULL)
            {
                it = it->getNext();
            }
            it->setNext(NULL);
            _tail = it;
        }
        T data_return = dNode->getData();
        delete dNode;
        _size--;
        return data_return;
    }
    T erase(size_t index)
    {
        if (_size == 0)
        {
            return this->_head->getData();
        }
        if (index == 0)
        {
            pop_front();
            return;
        }
        if ((index == _size - 1) || (index >= _size))
        {
            pop_back();
            return;
        }
        cNode<T> *it = _head;
        for (int i = 0; i < index - 1; i++)
        {
            it = it->getNext();
        }
        cNode<T> *dNode = it->getNext();
        it->setNext(dNode->getNext());
        T data_return = dNode->getData();
        delete dNode;
        _size--;
        return data_return;
    }

    //Iterator
    typedef cIterator<T> iterator;
    iterator begin()
    {
        return iterator(_head);
    }
    iterator end()
    {
        return iterator(NULL);
    }

    void printList()
    {
        cout << "List is ";
        if (_size == 0)
        {
            cout << "empty!" << endl;
            return;
        }
        cNode<T> *it = _head;
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
    size_t size()
    {
        return _size;
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
    T &at(size_t index)
    {
    }
};
#endif