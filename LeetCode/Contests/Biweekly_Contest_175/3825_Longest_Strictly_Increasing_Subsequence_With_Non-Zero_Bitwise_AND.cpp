/*
Problem: 3825. Longest Strictly Increasing Subsequence With Non-Zero Bitwise AND

You are given an integer array nums.

Return the length of the longest strictly increasing subsequence in nums whose bitwise AND is non-zero. If no such subsequence exists, return 0.

Approach:
- Iterate over each bit position from 0 to 30.
- For each bit, select numbers in the array where that bit is set.
- Compute the Longest Increasing Subsequence (LIS) of the selected numbers using binary search (patience sorting).
- Track the maximum LIS length across all bit positions.
- Handles edge cases such as arrays with all zeros or no valid subsequence.

Time Complexity:   O(31 * n log n) ≈ O(n log n)
Space Complexity:  O(n)
*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 31; i++){
            vector<int> temp;
            for(int& num: nums){
                if(num & (1 << i)){
                    auto it = lower_bound(temp.begin(), temp.end(), num);
                    if(it == temp.end()) temp.push_back(num);
                    else *it = num;
                }
            }
            res = max(res, (int)temp.size());
        }
        return res;
    }
};
