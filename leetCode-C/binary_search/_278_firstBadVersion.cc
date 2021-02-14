#include <iostream>

using namespace std;

bool isBadVersion(int version);
// 变种的二分查找，不是找某个值而是某一个分割点
// 类似于[#,#,#,#,#,#,#,$,$,$,$,$,$,$]中找最后一个#
int firstBadVersion(int n)
{
    int left = 1;
    int right = n;

    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        if (isBadVersion(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right;
}