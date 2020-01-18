/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 2)
        {
            return min(height[0], height[1]);
        }

        int max_area = 0;
        int current_max_area = 0;
        auto tail = height.end() - 1;
        for(auto it=height.begin(); it!=tail; it++)
        {
            for(auto it2=tail; it2!=it; it2--)
            {
                if(*it < *it2)
                {
                    current_max_area = *it * (it2 - it);
                    max_area = max_area > current_max_area ? max_area : current_max_area;
                    break;
                }
                else if(*it == *it2)
                {
                    current_max_area = *it * (it2 - it);
                    max_area = max_area > current_max_area ? max_area : current_max_area;
                    tail = it2;
                    break;
                }
                else
                {
                    current_max_area = *it2 * (it2 - it);
                    max_area = max_area > current_max_area ? max_area : current_max_area;
                    tail = it2;
                }
            }
        }
        return max_area;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> input{1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(input) << endl;
    return 0;
}