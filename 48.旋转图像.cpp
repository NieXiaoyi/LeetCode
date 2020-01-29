/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int edge = (matrix.size()-1) / 2;
        int tmp = 0;
        int n = matrix.size() - 1;
        //由外往内，一圈圈的旋转，i代表第i圈
        for(int i=0; i<=edge; i++)
        {
            //把一圈棋子旋转90°
            for(int j=i; j<=n-1-i; j++)
            {
                swap(matrix[i][j], matrix[j][n-i]);
                swap(matrix[i][j], matrix[n-i][n-j]);
                swap(matrix[i][j], matrix[n-j][i]);
            }
        }
    }
};
// @lc code=end

int main()
{
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{1, 2, 3});
    matrix.push_back(vector<int>{4, 5, 6});
    matrix.push_back(vector<int>{7, 8, 9});
    Solution s;
    s.rotate(matrix);
}