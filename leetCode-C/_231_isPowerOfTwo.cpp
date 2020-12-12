#include <iostream>

bool isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }
    return ((n & (n - 1)) == 0);
}

int main()
{
    using std::cout;
    using std::endl;

    cout << isPowerOfTwo(9) << endl;
}