/*
Problem: 3742. Maximum Path Score in a Grid

You are given an m x n grid where each cell contains 0, 1, or 2, and an integer k.

- 0: adds 0 to your score, costs 0
- 1: adds 1 to your score, costs 1
- 2: adds 2 to your score, costs 1

You start at (0,0) and want to reach (m-1,n-1) moving only right or down.
Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.

Approach:
- Use a 3D DP (i, j, currCost) representing the maximum score to reach cell (i,j) with a total cost of currCost.
- Recursively compute the maximum score from the top-left corner using memoization:
    - Base case: (0,0) must exactly match the current cost.
    - For other cells, consider coming from the left or top, subtracting the cost of the current cell.
- Loop over all possible total costs (0 to k) at the destination and pick the maximum score.

Time Complexity: O(m * n * k), each cell and cost computed at most once.
Space Complexity: O(m * n * k), for memoization.
*/

class Solution {
public:
    // Returns {score, cost} for a cell value
    pair<int, int> getScore(int num){
        if(num == 0) return {0, 0};
        if(num == 1) return {1, 1};
        return {2, 1};
    }

    // Recursive DP function
    // i, j: current cell coordinates
    // curr: current total cost
    // k: maximum allowed cost
    // grid: input grid
    // dp: memoization table
    int func(int i, int j, int curr, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        // If out of bounds or cost exceeds limits, return INT_MIN to denote invalid path
        if(i < 0 || j < 0 || curr < 0 || curr > k) return INT_MIN;

        // If already computed, return cached value
        if(dp[i][j][curr] != -1) return dp[i][j][curr];

        int src, crc;
        tie(src, crc) = getScore(grid[i][j]); // get score and cost of current cell

        // Base case: starting cell (0,0) must exactly match current cost
        if(i == 0 && j == 0){
            return (curr == crc) ? dp[i][j][curr] = src : INT_MIN;
        }

        int prev = curr - crc; // remaining cost after using current cell's cost
        if(prev < 0) return dp[i][j][curr] = INT_MIN; // invalid if remaining cost negative

        // Recursively get max score from top cell
        int up = func(i - 1, j, prev, k, grid, dp);
        up = (up != INT_MIN) ? up + src : INT_MIN; // add current score if valid

        // Recursively get max score from left cell
        int left = func(i, j - 1, prev, k, grid, dp);
        left = (left != INT_MIN) ? left + src : INT_MIN; // add current score if valid

        // Take maximum of top and left paths
        return dp[i][j][curr] = max(up, left);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // 3D DP table: dp[i][j][currCost] = max score to reach (i,j) with currCost
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int maxScore = -1;
        // Try all possible total costs at destination
        for(int c = 0; c <= k; c++){
            int score = func(m - 1, n - 1, c, k, grid, dp);
            if(score != INT_MIN) maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};
