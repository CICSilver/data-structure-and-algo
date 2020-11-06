#include <iostream>
#include <string>
using namespace std;

//空格替换成%20
string replaceSpace(string s) {
    char *str = (char *)s.data();
    string ret;
    int i = 0;
    string ans = "%20";
    for(auto& c:s)
    {
        if(c == ' ')
        {
            ret += ans;
        }else
        {
            ret.append(1,c);
        }
    }
    cout << ret << endl;
}

int main()
{
    string s = "asd f";
    replaceSpace(s);
}