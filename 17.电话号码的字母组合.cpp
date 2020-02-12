/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include<string>
#include<map>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    Solution ()
    {
        num2letters['2'] = "abc";
        num2letters['3'] = "def";
        num2letters['4'] = "ghi";
        num2letters['5'] = "jkl";
        num2letters['6'] = "mno";
        num2letters['7'] = "pqrs";
        num2letters['8'] = "tuv";
        num2letters['9'] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        {
            return vector<string>{};
        }
        vector<vector<string>> buf(2);
        buf[0] = vector<string>{""};
        buf[1] = vector<string>{""};
        int flag = 0;
        for(string::reverse_iterator it = digits.rbegin(); it!=digits.rend(); it++)
        {
            buf[flag].clear();
            for(auto chr : num2letters[*it])
            {
                for(auto str : buf[(flag+1)%2])
                {
                    (buf[flag]).push_back(chr + str);
                }
            }
            flag = (flag + 1) % 2;
        }
        return buf[(flag+1) % 2];
    }

private:
    map<char, string> num2letters;
};
// @lc code=end

