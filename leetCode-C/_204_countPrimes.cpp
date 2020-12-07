#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(int num)
{
    int mid = (int)sqrt((double)num);
    for (int i = 2; i <= mid; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
/**
 * @brief 埃氏筛
 * @param n 
 * @return int 
 */
int countPrimes_Era(int n)
{
    //为1的即未标记数，表示不知道是否为质数
    //为0的即标记数，表示不是质数
    int count = 0;
    vector<int> nums(n, 1);
    for (int i = 2; i < n; ++i)
    {
        if (isPrime(i))
        {
            for (long long t = i; (t * i) < n; ++t)
            {
                nums[t * i] = 0;
            }
            ++count;
        }
    }
    return count;
}

/**
 * @brief 暴力法，仅对判断进行了一次优化
 * @param n 
 * @return int 
 */
int countPrimes_force(int n)
{
    if (n < 6)
    {
        if (n <= 2)
        {
            return 0;
        }
        if (n == 3)
        {
            return 1;
        }
        if (n > 3 && n <= 5)
        {
            return 2;
        }
    }
    // n >= 6
    int count = 3;
    for (int i = 1; (6 * i) <= n; ++i)
    {
        int l = 6 * i - 1;
        int r = 6 * i + 1;
        // cout << 6 * i << endl;
        if (isPrime(l) && l > 5)
        {
            // cout << l << endl;
            ++count;
        }
        if (r < n && isPrime(r))
        {
            // cout << r << endl;
            ++count;
        }
    }
    return count;
}

int main()
{
    int ret = countPrimes_force(7);
    int ret2 = countPrimes_Era(7);
    cout << ret << endl;
    cout << ret2 << endl;
}
