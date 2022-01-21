#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // 顺序无关
    // 全部结果集
    // DFS
    unordered_map<char, string> GetPhoneMap()
    {
        unordered_map<char, string> phoneMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        return phoneMap;
    }
    vector<string> letterCombinations(string digits)
    {
        auto phoneMap = GetPhoneMap();
        vector<string> result;

        return result;
    }

    string func(string digits, string res)
    {
        auto phoneMap = GetPhoneMap();

    }
};

int main(int argc, char *argv[])
{

    return 0;
}