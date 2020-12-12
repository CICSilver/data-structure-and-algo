#include <string>
#include <sstream>
using namespace std;

bool isFlipedString(string s1, string s2)
{
    if(s1.size() != s2.size())
    {
        return false;
    }
    stringstream ss;
    ss << s2 << s2;
    string S;
    ss >> S;
    int res = S.find(s1);
    return res != -1;
}