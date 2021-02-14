#include <iostream>

using namespace std;

int add(int a, int b)
{
    while (b != 0)
    {
        // 异或计算无进位部分
        uint32_t sum = a ^ b;
        // 与 计算进位部分(保留相同位并左移一位)
        uint32_t carry = (a & b) << 1;
        a = sum;
        b = carry;
    }

    return a;
}

int main()
{
    cout << add(-1, 2) << endl;
}