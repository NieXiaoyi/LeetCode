/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        putBraket(n, 0, "");
        return vec;
    }
    void putBraket(int n, int m, string str)
    {
        if(m == 0)
        {
            if(n == 0)
            {
                vec.push_back(str);
            }
            else
            {
                putBraket(n-1, m+1, str+'(');
            }
        }
        else
        {
            if(n != 0)
            {
                putBraket(n-1, m+1, str+'(');
            }
            putBraket(n, m-1, str+')');
        }
    }
private:
    vector<string> vec;
};
// @lc code=end

