/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
#include <string>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        string ph = handlePattern(p);
        return isMatchHandled2(s, ph);
    }

    bool isMatchHandled(string s, string p) {
        if (s.empty() && p.empty())
        {
            return true;
        }
        if(p.empty() && !s.empty())
        {
            return false;
        }
        
        if(p.front()=='*')
        {
            return isMatchHandled(s, string(p.begin()+1, p.end())) || \
                (!s.empty() && isMatchHandled(string(s.begin()+1, s.end()), p));
        }
        if(!s.empty() && (s.front()==p.front() || p.front()=='?'))
        {
            return isMatchHandled(string(s.begin()+1, s.end()), string(p.begin()+1, p.end()));
        }
        
        return false;
    }

    bool isMatchHandled2(string s, string p)
    {
        bool match[s.length()+1][p.length()+1];
        for(int i=0; i<=s.length(); i++)
        {
            for(int j=0; j<=p.length(); j++)
            {
                match[i][j] = false;
            }
        }
        match[0][0] = true;
        for(int i=1; i<=s.length(); i++)
        {
            match[i][0] = false;
        }

        for(int i=0; i<=s.length(); i++)
        {
            for(int j=1; j<=p.length(); j++)
            {
                if(p[p.length()-j] == '*')
                {
                    match[i][j] = match[i][j-1] || (i!=0 && match[i-1][j]);
                }
                else if( i!=0 && (s[s.length()-i]==p[p.length()-j] || p[p.length()-j]=='?') )
                {
                    match[i][j] = match[i-1][j-1];
                }
            }
        }

        return match[s.length()][p.length()];
    }

    string handlePattern(string p)
    {
        string tmp;
        bool get = false;
        for(auto c:p)
        {
            if(c == '*')
            {
                if(get == true)
                {
                    continue;
                }
                get = true;
                tmp += c;
            }
            else
            {
                tmp += c;
                get = false;
            }
        }

        return tmp;
    }
};
// @lc code=end

int main()
{
    string s("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb");
    string p("b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a");
    Solution sol;
    cout << sol.isMatch(s, p) << endl;
}