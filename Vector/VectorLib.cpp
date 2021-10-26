#ifndef __VectorLib_cpp
#define __VectorLib_cpp
#include <iostream>
using namespace std;
template <class T>
class r_iterator
{
private:
    T *_it;

public:
    r_iterator()
    {
        _it = NULL;
    }
    r_iterator(T *o_it)
    {
        _it = o_it;
    }
    r_iterator(const r_iterator &other)
    {
        this->_it = other._it;
    }
    r_iterator &operator=(const r_iterator &other)
    {
        _it = other._it;
    }
    T operator*()
    {
        return *_it;
    }
    bool operator==(const r_iterator &other)
    {
        return _it == other._it;
    }
    bool operator!=(const r_iterator &other)
    {
        return _it != other._it;
    }
    r_iterator operator++(int) //prefix
    {
        return (--_it);
    }
    r_iterator operator++() //Postfix
    {
        return (_it--);
    }
};
template <class T>
class VectorLib
{
private:
    T *_element;
    size_t _size;     //Chỉ số lượng phần tử hiện có trong vector (Màu cam)
    size_t _capacity; //Chỉ số lượng phần tử tối đa vector có thể chứa (Màu xanh lá mạ)

public:
    VectorLib()
    {
        _size = 0;
        _capacity = 2;
        _element = new T[_capacity];
    }
    VectorLib(size_t nums, T value = 0)
    {
        _size = _capacity = nums;
        _element = new T[_capacity];
        for (int i = 0; i < _size; i++)
        {
            _element[i] = value;
        }
    }
    VectorLib(T *arr, size_t nums)
    {
        _size = _capacity = nums;
        _element = new T[_capacity];
        for (int i = 0; i < _size; i++)
        {
            _element[i] = arr[i];
        }
    }
    ~VectorLib()
    {
        delete[] _element; // Giải phóng vùng bộ nhớ được trỏ bởi _element
    }

    //Modify - Nâng cấp vector
    void extend()
    {
        _capacity = _capacity * 2;
        T *new_v;
        new_v = new T[_capacity];
        for (int i = 0; i < _size; i++)
        {
            new_v[i] = _element[i];
        }
        delete[] _element;
        _element = new_v;
    }
    void extend(size_t nums)
    {
        _capacity += nums;
        T *new_v;
        new_v = new T[_capacity];
        for (int i = 0; i < _size; i++)
        {
            new_v[i] = _element[i];
        }
        delete[] _element;
        _element = new_v;
    }
    void push_back(const T &value) //Thêm 1 phần tử vào cuối
    {
        if (full()) //Kiểm tra xem vector có đầy hay ko?
        {
            //Mở rộng vector
            extend();
        }
        _element[_size] = value;
        _size++;
    }
    void push_front(const T &value)
    {
        if (full())
        {
            extend();
        }
        for (size_t i = _size; i > 0; i--)
        {
            _element[i] = _element[i - 1];
        }
        _element[0] = value;
        _size++;
    }
    void insert(size_t index, const T &value)
    {
        if (full())
        {
            extend();
        }
        for (size_t i = _size - 1; i >= index; i--) //3, 2, 1
        {
            _element[i + 1] = _element[i];
            if (i == 0)
                break;
        }
        _element[index] = value;
        _size++;
    }
    T pop_back()
    {
        _size--;
        return _element[_size];
    }
    T pop_front()
    {
        T data = _element[0];
        for (size_t i = 1; i < _size; i++)
        {
            _element[i - 1] = _element[i];
        }
        _size--;
        return data;
    }
    T erase(size_t index)
    {
        T data = _element[index];
        for (size_t i = index + 1; i < _size; i++)
        {
            _element[i - 1] = _element[i];
        }
        _size--;
        return data;
    }

    // Iterator - Bộ lặp
    typedef T *iterator;
    iterator begin()
    {
        return _element;
    }
    iterator end()
    {
        return _element + _size;
    }
    typedef r_iterator<T> rIterator;
    rIterator rbegin()
    {
        return _element + _size - 1;
    }
    rIterator rend()
    {
        return _element - 1;
    }
    void print()
    {
        for (size_t i = 0; i < _size; i++)
        {
            cout << _element[i] << " ";
        }
        // cout << "size = " << _size << " capac = " << _capacity;
        cout << endl;
    }
    // Capacity - Kích thước
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
    bool full()
    {
        return (_size == _capacity);
    }

    // Accessible - Truy nhập các phần tử trong vector.
    T front() const //Trả về phần tử đầu tiên của vector
    {
        return _element[0];
    }
    T back() const //Trả về phần tử cuối cùng của vector
    {
        return _element[_size - 1];
    }
    T operator[](size_t index)
    {
        return _element[index];
    }
    T at(size_t index)
    {
        return _element[index];
    }
    T at(iterator it)
    {
        return *it;
    }
};
#endif