#ifndef __VectorLibrary__cpp
#define __VectorLibrary__cpp
template <class T>
class reverse_iterator_it
{
private:
    T *current;

public:
    reverse_iterator_it(T *c = 0) //NULL = 0
    {
        current = c;
    }
    T *get_current() const
    {
        return current;
    }
    reverse_iterator_it &operator=(const reverse_iterator_it &it)
    {
        current = it.current;
        return *this;
    }
    T &operator*() const
    {
        return *current;
    }
    bool operator!=(reverse_iterator_it it)
    {
        return current != it.get_current();
    }
    reverse_iterator_it operator++()
    {
        return --current;
    }
    reverse_iterator_it operator++(int)
    {
        return current--;
    }
};
template <class T>
class VectorLibrary
{
private:
    T *buff;
    int num; //Lưu trữ số phần tử hiện tại của vector;
    int cap; //Khả năng lưu trữ hiện tại;
public:
    VectorLibrary()
    {
        num = 0;
        cap = 1;
        buff = new T[cap];
    }
    VectorLibrary(int n, T x) //Constructor khai báo vector với n phần tử có giá trị x
    {
        num = n;
        cap = n;
        buff = new T[cap];
        for (int i = 0; i < cap; i++)
        {
            buff[i] = x; //Gán các giá trị của vector cho giá trị đã cho
        }
    }
    VectorLibrary(T *x, int n) //Constructor khởi tạo vector từ một mảng có n phần tử
    {
        num = n;
        cap = n;
        for (int i = 0; i < cap; i++)
        {
            buff[i] = x[i]; //Gán các giá trị của vector cho giá trị các phần tử của mảng
        }
    }
    ~VectorLibrary() //Deconstructor giải phóng bộ nhớ đã cấp phát cho các phần tử của vector
    {
        delete[] buff;
    }
    VectorLibrary &operator=(const VectorLibrary &o_vector)
    {
        this->num = o_vector.num;
        this->cap = o_vector.cap;
        if (buff)
        {
            delete[] buff;
        }
        buff = new T[cap];
        for (int i = 0; i < num; i++) //i < n vì ta chỉ gán các phần tử hiện có trong vector mà thôi. cap là số phần tử được khai báo tối đa.
        {
            buff[i] = o_vector.buff[i];
        }
        return *this;
    }

public: //Modifier
    void assign(int size, int value)
    {
        if (num + size > cap)
        {
            extend(2 * cap);
        }
        for (int i = num; i < num + size; i++)
        {
            buff[i] = value;
        }
        num += size;
    }
    void pop_back() //Lấy ra một phần tử
    {
        if (num > 0)
        {
            num--;
        }
    }
    void push_back(const T &new_element)
    {
        if (num == cap) //Kiểm tra xem số lượng phần tử hiện có có bằng dung lượng không. Nếu có (vector đầy) thì tăng dung lượng lên 2 lần
        {
            extend(2 * cap);
        }
        buff[num] = new_element; //Gán phần tử mới tại vị trí cuối cùng của mảng
        num++;                   //Tăng số lượng phần tử hiện có lên 1;
    }
    void extend(const int &newcap) //Mở rộng thêm vùng nhớ cho vector
    {
        if (newcap > cap)
        {
            cap = newcap;
            T *temp = new T[cap];
            for (int i = 0; i < num; i++)
            {
                temp[i] = buff[i];
            }
            if (buff) //Kiểm tra xem các phần tử có tồn tại hay ko
            {
                delete[] buff;
            }
            buff = temp;
        }
    }
    void insert(int index_insert, const T &insert_element)
    {
        if (num == cap)
        {
            extend(2 * cap);
        }
        for (int i = num - 1; i >= index_insert; i--)
        {
            buff[i + 1] = buff[i];
        }
        buff[index_insert] = insert_element;
    }
    void erase(int index) // Xoá một phần tử ở vị trí k
    {
        for (int i = index; i < num - 1; i++)
        {
            buff[i] = buff[i + 1];
        }
        num--;
    }
    void erase(int start_index, int end_index)
    {
        for (int i = start_index; i < (num - end_index + start_index); i++)
        {
            buff[i] = buff[i + end_index - start_index];
        }
        num -= (end_index - start_index);
    }

public: //Capacity
    int size()
    {
        return num;
    }
    int capacity()
    {
        return cap;
    }
    bool empty()
    {
        if (num == 0)
            return true;
        else
            return false;
    }

public: //Element Access
    T &operator[](int index)
    {
        return buff[index];
    }
    T &front()
    {
        return buff[0];
    }
    T &back()
    {
        return buff[num - 1];
    }
    T &at(int position)
    {
        return buff[position];
    }

public: //Iterator
    typedef T *iterator;
    iterator begin()
    {
        return buff;
    }
    iterator end()
    {
        return buff + num;
    }
    typedef reverse_iterator_it<T> reverse_iterator;
    reverse_iterator rbegin()
    {
        return reverse_iterator(buff + num - 1);
    }
    reverse_iterator rend()
    {
        return reverse_iterator(buff - 1);
    }
};
#endif