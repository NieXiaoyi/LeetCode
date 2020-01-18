/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include<iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        int num = 0;
        int old_num = 0;
        bool negative = false;
        auto it = str.begin();
        while(*it==' ' && it!=str.end())
        {
            it++;
        }
        if(it == str.end())
        {
            return num;
        }

        if(*it == '-')
        {
            negative = true;
            it++;
        }
        else if(*it == '+')
        {
            it++;
        }

        if(negative)
        {
            while(*it<='9' && *it>='0' && it!=str.end())
            {
                if((num < -214748364) ||(num == -214748364 && *it > '8'))
                {
                    return -2147483648;
                }
                num = int(num*10) - (*it - '0');
                it++;
            }
        }
        else
        {
            while(*it<='9' && *it>='0' && it!=str.end())
            {
                if((num > 214748364) || (num == 214748364 && *it > '7'))
                {
                    return 2147483647;
                }
                num = int(num*10) + (*it - '0');
                it++;
            }
        }

        return num;
    }
};
// @lc code=end


int main()
{
    cout << Solution().myAtoi("42") << endl;
    return 0;
}