#include <iostream>
#include <vector>

using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    int five_size = 0;
    int ten_size = 0;

    for (auto const &b : bills)
    {
        switch (b)
        {
        case 5:
        {
            ++five_size;
            break;
        }
        case 10:
        {
            if (five_size == 0)
            {
                return false;
            }
            else
            {
                ++ten_size;
                --five_size;
            }
            break;
        }
        case 20:
        {
            if (ten_size > 0 && five_size > 0)
            {
                --ten_size;
                --five_size;
            }
            else if (five_size >= 3)
            {
                five_size -= 3;
            }
            else
            {
                return false;
            }
            break;
        }
        default:
            break;
        }
        cout << "five_size = " << five_size << endl;
        cout << "ten_size = " << ten_size << endl;
    }
    return true;
}