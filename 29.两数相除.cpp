/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        int symbol = 1;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        {
            symbol = -1;
        }
        uint32_t dd = abs(long(dividend));
        uint32_t dv = abs(long(divisor));
        if(dd < dv)
        {
            return 0;
        }

        uint32_t ret = div(dd, dv);
        if(ret > 2147483648)
        {
            return 2147483647;
        }
        else if(ret == 2147483648)
        {
            if(symbol > 0)
            {
                return 2147483647;
            }
            else
            {
                return -2147483648;
            }
            
        }

        return int(symbol * ret);
    }

    uint32_t div(uint32_t dd, uint32_t dv)
    {
        if(dd < dv)
        {
            return 0;
        }

        uint32_t cnt = 1;
        uint32_t sum = dv;
        uint32_t tmp = sum;
        while(1)
        {
            if(sum == dd)
            {
                return cnt;
            }
            sum += sum;
            if(sum > dd)
            {
                sum -= tmp;
                return cnt + div(dd-sum, dv);
            }
            cnt += cnt;
            tmp = sum;
        }
    }
};
// @lc code=end

