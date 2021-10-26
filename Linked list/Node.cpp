#ifndef __Node_cpp
#define __Node_cpp
#include <iostream>
using namespace std;
template <class T>
class cNode //class Node
{
private:
    T _data;
    cNode<T> *_next; //link
public:
    cNode<T>()
    {
        _next = 0;
    }
    cNode<T>(T data, cNode<T> *next)
    {
        _data = data;
        _next = next;
    }
    T &getData()
    {
        return _data;
    }
    void setData(const T &data)
    {
        _data = data;
    }
    cNode<T> *getNext()
    {
        return _next;
    }
    void setNext(cNode<T> *next)
    {
        _next = next;
    }
};
// (100) --> (5, 120) --> (6, 228) --> ... --> (20, 0) --> NULL
//              100         120                 400
#endif