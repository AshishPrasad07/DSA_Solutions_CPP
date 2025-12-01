/*
Problem: 329. Longest Increasing Path in a Matrix

Given an m x n integer matrix, return the length of the longest increasing path in the matrix.

You can move from a cell in four directions: up, down, left, or right. 
Diagonal moves or wrap-around are not allowed.

Goal:
Find the length of the longest strictly increasing path.

Approach:
- Use DFS to explore paths starting from each cell.
- Use memoization (dp) to store longest path starting from each cell to avoid recomputation.
- For each cell, check all four directions:
    - If the next cell is larger, recurse and extend path length.
- Keep track of the maximum length found across all cells.

Time Complexity: O(m * n)  
Space Complexity: O(m * n) (for dp array + recursion stack)
*/

class Solution {
public:
    // DFS function to find longest increasing path starting from (i, j)
    int func(int i, int j, vector<vector<int>>& nums, vector<vector<int>>& dp){
        if(i < 0 || j < 0 || j == nums[0].size() || i == nums.size()){
            return 0;  // out of bounds
        }

        if(dp[i][j] != -1)
            return dp[i][j];  // return memoized value

        int up = 1;
        if(i - 1 >= 0 && nums[i][j] < nums[i - 1][j]){
            up = up + func(i - 1, j, nums, dp);
        }

        int down = 1;
        if(i + 1 < nums.size() && nums[i][j] < nums[i + 1][j]){
            down = down + func(i + 1, j, nums, dp);
        }

        int right = 1;
        if(j + 1 < nums[0].size() && nums[i][j] < nums[i][j + 1]){
            right = right + func(i, j + 1, nums, dp);
        }

        int left = 1;
        if(j - 1 >= 0 && nums[i][j] < nums[i][j - 1]){
            left = left + func(i, j - 1, nums, dp);
        }

        int maxi = up;
        maxi = max(maxi, down);
        maxi = max(maxi, right);
        return dp[i][j] = max(maxi, left);  // memoize result
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));  // memoization table
        int maxi = 1;  // store overall maximum path length

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxi = max(maxi, func(i, j, matrix, dp));  // check path from each cell
            }
        }

        return maxi;  // return longest path found
    }
};
