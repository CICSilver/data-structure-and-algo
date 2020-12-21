#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string addStr(vector<string> &_nums)
{
    vector<stack<int>> s_nums;
    for (auto const &s : _nums)
    {
        stack<int> s_eachNum;
        for (auto const &c : s)
        {
            auto temp_c = c;
            s_eachNum.push(atoi(&temp_c));
        }
        s_nums.emplace_back(s_eachNum);
    }

    bool isDone = false;
    int carry = 0;
    string res;
    while (1)
    {
        int eachSum = 0;
        for (auto &stack : s_nums)
        {
            if (!stack.empty())
            {
                isDone = false;
                auto temp = eachSum;
                eachSum += stack.top();
                // printf("%d + %d + %d= %d\n", temp, stack.top(), carry, eachSum + carry);
                stack.pop();
            }
            else
            {
                isDone = true;
            }
        }
        if(isDone)
        {
            break;
        }
        eachSum += carry;
        if ((eachSum / 10) != 0)
        {
            res += to_string(eachSum % 10);
            // cout << "carry with.... " <<  << endl;
            carry = eachSum / 10;
        }
        else
        {
            res += to_string(eachSum);
            carry = 0;
        }
        // cout << res << endl;
    }
    reverse(res.begin(), res.end());
    return res;
}

// 非负整数
// 不可直接转换为大数类型
// num1和num2的长度小于110
// num1和num2只包含数字0-9

//       1 2 3
//     * 4 5 6
//     -------------
//       7 3 8
//     6 1 5 0          ---->存入multi_res
//   4 9 2 0 0
// -------------------
//   5 6 0 8 8          ---->按位加即可
string multiply(string &num1, string &num2)
{
    if (num1 == "0" || num2 == "0")
    {
        return "0";
    }
    vector<int> i_num1;
    vector<int> i_num2;
    vector<string> multi_res;

    for (auto n1 : num1)
    {
        i_num1.push_back(atoi(&n1));
    }
    for (auto n2 : num2)
    {
        i_num2.push_back(atoi(&n2));
    }

    // 获取各乘结果
    int count = -1;
    for (auto it2 = i_num2.rbegin(); it2 != i_num2.rend(); ++it2)
    {
        ++count;
        auto mutliplicand = *it2;
        int carry = 0;
        string eachMultiRes = "";
        for (auto it1 = i_num1.rbegin(); it1 != i_num1.rend(); ++it1)
        {
            auto mutiplier = *it1;
            auto res = mutiplier * mutliplicand + carry;
            if (res % 10 != 0)
            {
                // 有进位
                eachMultiRes += to_string(res % 10);
                carry = res / 10;
            }
            else
            {
                eachMultiRes += to_string(res);
                carry = 0;
            }
        }
        reverse(eachMultiRes.begin(), eachMultiRes.end());
        auto temp = count;
        while (temp-- != 0)
        {
            eachMultiRes += '0';
        }
        multi_res.emplace_back(eachMultiRes);
    }

    for (auto s : multi_res)
    {
        cout << s << endl;
    }

    // 结果相加

    return addStr(multi_res);
}

int main()
{
    string num1 = "2";
    string num2 = "3";
    multiply(num1, num2);
    // char c ='3';
    // printf("%d\n", c);
}
