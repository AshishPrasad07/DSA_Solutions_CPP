/*
Problem: 3796. Find Maximum Value in a Constrained Sequence

You are given an integer n, a 2D array restrictions, and an integer array diff of length n-1.  

Construct a sequence of length n such that:
- a[0] = 0
- All elements are non-negative
- For 0 <= i <= n-2, abs(a[i] - a[i+1]) <= diff[i]
- For each restrictions[i] = [idx, maxVal], a[idx] <= maxVal  

Return the largest value in a valid sequence.

Approach:
- Initialize a sequence array with INT_MAX and set a[0] = 0.
- Apply the restrictions to the corresponding indices.
- Perform a left-to-right pass to enforce diff constraints.
- Perform a right-to-left pass to enforce diff constraints again.
- The maximum value in the sequence after both passes is the answer.

Time Complexity:   O(n + m)   // n = sequence length, m = number of restrictions
Space Complexity:  O(n)
*/

class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> seq(n, INT_MAX);
        seq[0] = 0;
        int m = restrictions.size();
        for(int i = 0; i < m; i++){
            int idx = restrictions[i][0];
            int maxVal = restrictions[i][1];
            seq[idx] = min(seq[idx], maxVal);
        }
        for(int i = 0; i < n - 1; i++){
            seq[i + 1] = min(seq[i + 1], seq[i] + diff[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            seq[i] = min(seq[i], seq[i + 1] + diff[i]);
        }
        int res = 0;
        for(int num: seq){
            res = max(res, num);
        }
        return res;
    }
};
