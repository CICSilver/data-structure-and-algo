#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string reverseWords(string s)
{
    if (s == "" || s == " ")
    {
        return s;
    }
    vector<string> words;
    int spacePos = 0;
    int lastPos = 0;
    while (spacePos != -1)
    {
        spacePos = s.find(' ', lastPos);
        string temp = s.substr(lastPos, spacePos - lastPos);
        reverse(temp.begin(), temp.end());
        // cout << temp << endl;
        lastPos = spacePos + 1;
        words.emplace_back(temp);
    }

    string res("");
    for (auto const &word : words)
    {
        res += word + " ";
    }
    auto it = res.end();
    res.erase(it - 1);
    return res;
}

int main()
{
    string s = "Let's take LeetCode contest";
    // reverseWords(s);
    cout<< reverseWords(s) << endl;
}