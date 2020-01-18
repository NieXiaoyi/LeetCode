#include <iostream>
#include <string>
using namespace std;

/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)
        {
            return s;
        }

        string ret(s);
        int k = 0;
        for(int i=0; i<numRows; i++)
        {
            int j = 0;
            while(1)
            {
                int base = j*(2*numRows-2);
                int left = base - i;
                if(left >= 0)
                {
                    if(left >= s.length())
                    {
                        break;
                    }
                    ret[k] = s[left];
                    k++;
                }

                if(i==0 || i==numRows-1)
                {
                    j++;
                    continue;
                }
                
                int right = base + i;
                if(right >= s.length())
                {
                    break;
                }
                ret[k] = s[right];
                k++;
                j++;
            }
        }
        return ret;
    }
};
// @lc code=end

int main()
{
    string s = "LEET";
    cout << Solution().convert(s, 1) << endl;
    return 0;
}