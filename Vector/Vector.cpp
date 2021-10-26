#ifndef __Vector_cpp
#define __Vector_cpp
template <class T>
class Vector
{
private:
    int vector_size;
    int vector_capacity;
    T *element;
    void alloc()
    {
        if (vector_size == vector_capacity)
        {
            vector_capacity *= 2;
        }
        element = new T[vector_capacity];
    }

public:
    Vector()
    {
        this->vector_size = 0;
        this->vector_capacity = 1;
        alloc();
    }
    Vector(int cap)
    {
        }
    ~Vector();
};

#endif