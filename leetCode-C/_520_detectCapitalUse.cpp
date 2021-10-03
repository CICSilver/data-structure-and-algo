#include <string>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

// [65,90]
bool detectCapitalUse(string word) 
{
    // 长度小于2的全部正确
    cout << word.size() << endl;
    if(word.size() < 2)
    {
        return true;
    }

    // 1.判断首字母是否为大写
    if(word[0] <= 'Z')
    {
        // 全部大写或小写
        if(word[1] <= 'Z')
        {
            // 全部大写
            for(int i = 1; i < word.size(); ++i)
            {
                cout << word[i] << endl;
                if(word[i] > 'Z')
                {
                    cout << "cur char = " << word[i] << endl;
                    return false;
                }
            }
        }else
        {
            // 全部小写
            for(int i = 1; i < word.size(); ++i)
            {
                cout << word[i] << endl;
                if(word[i] < 'a')
                {
                    cout << "cur char = " << word[i] << endl;
                    return false;
                }
            }
        }
        char sec = word[1];
        for(int i = 2; i < word.size(); ++i)
        {
            int ret = fabs(word[i] - sec);
            cout << word[i] << " - " << sec << " = " << ret << endl;
            if(ret >= 25)
            {
                return false;
            }
        }
    }else
    {
        cout << word << endl;
        // 全部小写则正确
        for(int i = 1; i < word.size(); ++i)
        {
            cout << word[i] << endl;
            if(word[i] < 'a')
            {
                cout << "cur char = " << word[i] << endl;
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char* argv[])
{
    string s = "XawQ";
    char c = 'Z';
    char a = 'a';
    cout << detectCapitalUse(s) << endl;
    return 0;
}