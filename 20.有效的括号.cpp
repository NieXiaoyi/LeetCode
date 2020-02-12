/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <stack>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
       stack<char> left;
       for(auto chr : s)
       {
           switch(chr)
           {
               case '(':    
               case '[':    
               case '{':    left.push(chr); break;
               case ')':    
                    if(!left.empty() && left.top() == '(')
                    {
                        left.pop();
                        break;
                    }
                    else
                    {
                        return false;
                    }
               case ']':
                    if(!left.empty() && left.top() == '[')
                    {
                        left.pop();
                        break;
                    }
                    else
                    {
                        return false;
                    }
               case '}':
                    if(!left.empty() && left.top() == '{')
                    {
                        left.pop();
                        break;
                    }
                    else
                    {
                        return false;
                    }
               default: return false;
           }
       }
       if(left.empty())
       {
            return true;
       }
        return false;
    }
};
// @lc code=end

