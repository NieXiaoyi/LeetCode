/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.empty() && p.empty())
        {
            return true;
        }
        if(p.empty() && !s.empty())
        {
            return false;
        }

        if(p.length()>=2 && p[1]=='*')
        {
            return isMatch(s, string(p.begin()+2, p.end())) || \
                (!s.empty() && (s[0]==p[0] || p[0]=='.') && isMatch(string(s.begin()+1, s.end()), p));
        }

        if(!s.empty() && (s[0]==p[0] || p[0]=='.'))
        {
            return isMatch(string(s.begin()+1, s.end()), string(p.begin()+1, p.end()));
        }

        return false;
    }
};
// @lc code=end

int main()
{
    Solution s;
    bool ret = s.isMatch("ab", ".*c");
    cout << ret << endl;

    return 0;
}