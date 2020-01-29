/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() < 2)
        {
            return vector<int>{};
        }

        vector<int>origin_nums(nums);

        sort(nums.begin(), nums.end());
        
        vector<int> ret;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]>=0 && nums[i]>target)
            {
                break;
            }
            int head = i+1;
            int tail = nums.size() - 1;
            int j = (head + tail)/2;
            while(1)
            {
                if(nums[j] == target-nums[i])
                {
                    ret = {nums[i], nums[j]};
                    goto index;
                }

                if(tail <= head)
                {
                    break;
                }

                if(nums[j] < target-nums[i])
                {
                    head = j+1;
                    j = (head + tail) / 2;
                }
                else
                {
                    tail = j-1;
                    j = (head + tail) / 2;
                }
            }
        }

index:
        if(ret.empty())
        {
            return vector<int>{};
        }

        vector<int>ret2;
        for(int i=0; i<origin_nums.size() && ret2.size()<2; i++)
        {
            if(origin_nums[i] == ret[0])
            {
                ret2.push_back(i);
            }
            else if(origin_nums[i] == ret[1])
            {
                ret2.push_back(i);
            }
        }

        return ret2;
    }
};
// @lc code=end


int main()
{
    Solution s;
    vector<int>input{3, 2, 4};
    s.twoSum(input, 6);
    return 0;
}