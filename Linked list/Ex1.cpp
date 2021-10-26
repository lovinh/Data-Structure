#include <bits/stdc++.h>
#include "LinkedList.cpp"
//Chuyển một số thập phân sang số nhị phân. In số đó ra màn hình.
void convertToBinary(size_t n)
{
    cList<int> container;
    while (n != 0)
    {
        container.push_back(n % 2);
        n = n / 2;
    }
    while (!container.empty())
    {
        std::cout << container.pop_back();
    }
    std::cout << std::endl;
}
int main(int argc, char const *argv[])
{
    size_t n;
    std::cout << "Nhap n: ";
    std::cin >> n;
    std::cout << "So nhi phan tuong ung cua n: ";
    convertToBinary(n);
    return 0;
}
