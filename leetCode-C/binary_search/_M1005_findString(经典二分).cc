#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 有序 稀疏数组 搜索指定字符串 命中返回下标 否则返回-1
int findString(vector<string> &words, string s)
{
    int left = 0;
    int right = words.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) >> 1;

        while (mid > left && words[mid].empty())
        {
            --mid;
        }
        if (words[mid] == s)
        {
            return mid;
        }
        else if (words[mid] > s)
        {
            right = mid - 1;
        }else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
}