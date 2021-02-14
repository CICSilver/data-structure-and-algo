#include <iostream>
#include <vector>

using namespace std;

// 判断num是否为完全平方数
// 无固定边界的二分查找
// 4, 9, 16
bool isPerfectSquare(int num)
{
    if(num < 2)
    {
        return true;
    }

    int left = 1;
    int right = num / 2;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if(mid * mid == num)
        {
            return true;
        }else if(mid * mid < num)
        {
            left = mid + 1;
        }else
        {
            right = mid;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    cout << isPerfectSquare(atoi(argv[1])) << endl;
}