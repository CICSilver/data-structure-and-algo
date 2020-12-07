#include <string>
#include <iostream>

using namespace std;

/**
 * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
 * 请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
 * 
 * 示例 1：
 * 
 * 输入: s = "abcdefg", k = 2
 * 输出: "cdefgab"
 * 示例 2：
 * 
 * 输入: s = "lrloseumgh", k = 6
 * 输出: "umghlrlose"
 *  
 * 
 * 限制：
 * 
 * 1 <= k < s.length <= 10000
 * 
 * 
 * @param s 
 * @param n 
 * @return string 
 */
string reverseLeftWords(string s, int n)
{
    string t1 = s.substr(0, n);
    string t2 = s.substr(n, s.size() - n);
    cout << "t1 = " << t1 << endl;
    cout << "t2 = " << t2 << endl;
    return t2 + t1;
}

int main()
{
    string s1 = "lrloseumgh";
    string res = reverseLeftWords(s1, 6);
    cout << res << endl;
}