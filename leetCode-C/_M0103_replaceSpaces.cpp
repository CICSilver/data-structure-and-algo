#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string replaceSpaces(string S, int length)
{
    // int diff = S.size() - length;
    if (S.size() == 0 || length >= S.size() || length < 0)
    {
        return S;
    }
    string s = S.substr(0, length);
    S = "";
    vector<string> words;

    int epos = 0;
    int lpos = 0;
    while (epos != -1)
    {
        epos = s.find(' ', lpos);
        string word = s.substr(lpos, epos - lpos);
        lpos = epos + 1;
        words.emplace_back(word);
        // cout << word << endl;
        // cout << epos << endl;
        // cout << lpos << endl;
    }

    for (auto const &word : words)
    {
        S += word + "%20";
    }
    auto it = S.end() - 3;
    S.erase(S.size() - 3, 3);

    return S;
}

int main()
{
    string s = "          ";
    s = replaceSpaces(s, 5);
    cout << "s = " << s << endl;
    cout << "s.size = " << s.size() << endl;
}