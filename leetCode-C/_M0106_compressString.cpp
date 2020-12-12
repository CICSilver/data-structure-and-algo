#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

string compressString(string S)
{
    if (S.size() <= 1)
    {
        return S;
    }
    stringstream ss;
    string ret = "";
    int lastPos = 0;
    int res = 0;
    while (res != -1)
    {
        res = S.find_first_not_of(S[lastPos], lastPos);
        if (res != -1)
        {
            ss << S[lastPos] << res - lastPos;
        }
        else
        {
            ss << S[lastPos] << S.size() - lastPos;
        }
        lastPos = res;
    }
    ss >> ret;
    
    return ret.size() <= S.size()?ret:S;
}

int main()
{
    string S = "aabcccccaaa";

    cout << compressString(S) << endl;
}