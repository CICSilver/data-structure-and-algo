#include <iostream>
#include <bitset>

int hammingWeight(uint32_t n)
{
    size_t res = 0;
    while (n)
    {
        res += n % 2;
        n >>= 1;
    }
    std::bitset<32> b_set(11111111111111111111111111111101);

    printf("%d\n", b_set.count());
    return res;
}

int main()
{
    // uint32_t num = 11111111111111111111111111111101;
    hammingWeight(1101);
}