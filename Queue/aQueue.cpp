#ifndef __aQueue_cpp
#define __aQueue_cpp
#define DEFAULT_CAPACITY 100
#include <stdio.h>
template <class T>
class aQueue
{
private:
    T *_element;
    unsigned int _front;
    unsigned int _back;
    unsigned int _size;
    unsigned int _capacity;

public:
    aQueue()
    {
        _capacity = DEFAULT_CAPACITY;
        _element = new T[_capacity];
        _front = _back = 0;
        _size = 0;
    }
    aQueue(const unsigned int cap)
    {
        _capacity = cap;
        _element = new T[_capacity];
        _front = _back = 0;
        _size = 0;
    }
    ~aQueue()
    {
        delete[] _element;
    }
    void push(const T &data)
    {
        if (_front == _back && _size != 0)
        {
            printf("Error: Queue is full");
            return;
        }
        _element[_back] = data;
        _back = (_back + 1) % _capacity;
        _size++;
    }
    T pop()
    {
        T ret_val;
        if (_front == _back && _size == 0)
        {
            printf("Error: Queue is empty! Cannot pop!");
            return ret_val;
        }
        ret_val = _element[_front];
        _front = (_front + 1) % _capacity;
        _size--;
        return ret_val;
    }
    T front() const
    {
        return _element[_front];
    }
    T back() const
    {
        return _element[_back - 1];
    }
    unsigned int size() const
    {
        return _size;
    }
    bool empty()
    {
        return (_size == 0);
    }
};
#endif