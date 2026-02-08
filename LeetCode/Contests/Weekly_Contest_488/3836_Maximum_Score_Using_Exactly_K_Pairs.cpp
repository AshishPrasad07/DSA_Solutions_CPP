/*
Problem: 3836. Maximum Score Using Exactly K Pairs

You are given two integer arrays nums1 and nums2 of lengths n and m respectively, and integer k.  
Select exactly k pairs of indices (i, j) such that:
- 0 <= i1 < i2 < ... < ik < n
- 0 <= j1 < j2 < ... < jk < m
Score = sum(nums1[i] * nums2[j]) over all pairs.  
Return the maximum score.

Approach:
- Treat it as a knapsack-style DP problem.  
- dp[i][j][r] = max score using first i of nums1, first j of nums2, selecting exactly r pairs.  
- Decision: take current pair (i,j) or skip an element from either array.  
- Initially implemented top-down recursive + memoization (TLE on large test cases).  
- Converted to iterative DP to eliminate recursion overhead while keeping take-or-not-take logic.

Time Complexity:   O(m * n * k)  
Space Complexity:  O(m * n * k)
*/

class Solution {
public:
    int m, n;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        m = nums1.size(); n = nums2.size();
        vector<vector<vector<long long>>> dp(m + 1, vector<vector<long long>>(n + 1, vector<long long>(k + 1, LLONG_MIN)));
        for(int i = 0; i <= m; i++)
            for(int j = 0; j <= n; j++)
                dp[i][j][0] = 0;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                for(int r = 1; r <= k; r++){
                    long long take = LLONG_MIN;
                    if(dp[i - 1][j - 1][r - 1] != LLONG_MIN)
                        take = 1LL * nums1[i - 1] * nums2[j - 1] + dp[i - 1][j - 1][r - 1];
                    long long skip1 = dp[i - 1][j][r], skip2 = dp[i][j - 1][r];
                    dp[i][j][r] = max({take, skip1, skip2});
                }
            }
        }
        return dp[m][n][k];
    }
};
