#ifndef __StackLib_cpp
#define __StackLib_cpp
#include <stdio.h>
template <class T>
class StackLib
{
private:
    T *_element;
    size_t _size;
    size_t _capacity;
    void extend()
    {
        _capacity *= 2;
        T *new_alloc = new T[_capacity];
        for (size_t i = 0; i < _size; i++)
        {
            new_alloc[i] = _element[i];
        }
        delete[] _element;
        _element = new_alloc;
    }

public:
    StackLib()
    {
        _size = 0;
        _capacity = 2;
        _element = new T[_capacity];
    }
    StackLib(const T &value, const size_t &size) //Tạo một stack chứa sẵn size phần tử có giá trị là value.
    {
        _capacity = size;
        extend();
        _size = size;
        for (int i = 0; i < size; i++)
        {
            _element[i] = value;
        }
    }
    StackLib(T *array, const size_t &size)
    {
        _capacity = size;
        extend();
        _size = size;
        for (int i = 0; i < size; i++)
        {
            _element[i] = array[i];
        }
    }
    void push(const T &value)
    {
        if (_size == _capacity)
        {
            extend();
        }
        _element[_size] = value;
        _size++;
    }
    T pop()
    {
        T res = _element[_size - 1];
        _size--;
        return res;
    }
    T top() const
    {
        return _element[_size - 1];
    }
    size_t size() const
    {
        return _size;
    }
    size_t capacity() const
    {
        return _capacity;
    }
    bool empty()
    {
        return (_size == 0);
    }
    ~StackLib()
    {
        delete[] _element;
    }
};
#endif