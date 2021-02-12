#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

/**
 * 整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。
 * 
 * 示例1:
 * 
 *  输入：A = 29 （或者0b11101）, B = 15（或者0b01111）
 *  输出：2
 * 示例2:
 * 
 *  输入：A = 1，B = 2
 *  输出：2
 * 
 * A，B范围在[-2147483648, 2147483647]之间
 */
int convertInteger(int A, int B)
{
    bitset<32> ret = A ^ B;
    
    int count = ret.count();
    cout << count << endl;

    return count;
}

int main(int argc, char *argv[])
{
    int A = 29;
    int B = 15;
    convertInteger(A, B);
}