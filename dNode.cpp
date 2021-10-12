#ifndef __dNode_cpp
#define __dNode_cpp
#include <iostream>
using namespace std;
template <class T>
class dNode
{
private:
    T _data;
    dNode<T> *_pre;
    dNode<T> *_next;

public:
    dNode()
    {
        _pre = _next = NULL;
    }
    dNode(const T &data, dNode<T> *pre, dNode<T> *next)
    {
        _pre = pre;
        _next = next;
        _data = data;
    }
    T &getData()
    {
        return _data;
    }
    void setData(const T &data)
    {
        _data = data;
    }
    dNode<T> *getPrevious()
    {
        return _pre;
    }
    void setPrevious(dNode<T> *pre)
    {
        _pre = pre;
    }
    dNode<T> *getNext()
    {
        return _next;
    }
    void setNext(dNode<T> *next)
    {
        _next = next;
    }
};
#endif