/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2)
        {
            return;
        }

        int index_been_swap = -1;
        for(int i=nums.size()-2; i>=0; i--)
        {
            if(nums[i] >= nums[i+1])
            {
                continue;
            }
            else
            {
                index_been_swap = i;
                int index = findMinimumGreater(nums, i+1, nums.size()-1, nums[i]);
                int swap = nums[index];
                nums[index] = nums[i];
                nums[i] = swap;
                break;
            }
        }

        for(int i=index_been_swap+1, j=nums.size()-1; i<j; i++, j--)
        {
            int swap = nums[i];
            nums[i] = nums[j];
            nums[j] = swap;
        }
    }

    int findMinimumGreater(vector<int>& nums, int first, int last, int value)
    {
        int mid = 0;
        int index = 0;
        while(first <= last)
        {
            mid = (first+last)/2;
            if(nums[mid] > value)
            {
                first = mid+1;
                index = mid;
            }
            else
            {
                last = mid-1;
            }
        }

        return index;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> a{1, 2, 3};
    s.nextPermutation(a);

    return 0;
}