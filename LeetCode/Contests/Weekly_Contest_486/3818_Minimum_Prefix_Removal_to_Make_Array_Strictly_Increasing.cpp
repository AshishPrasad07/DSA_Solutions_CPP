/*
Problem: 3818. Minimum Prefix Removal to Make Array Strictly Increasing

You are given an integer array nums. You need to remove exactly one prefix 
(possibly empty) from nums. Return an integer denoting the minimum length of 
the removed prefix such that the remaining array is strictly increasing.

Approach:
- Traverse the array from right to left.
- Find the first index where nums[i - 1] >= nums[i].
- Removing the prefix up to this index ensures the remaining suffix is strictly increasing.
- If no such index exists, the array is already strictly increasing.

Time Complexity:   O(n)
Space Complexity:  O(1)
*/

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = n - 1; i > 0; i--){
            if(nums[i - 1] >= nums[i]){
                res = i;
                break;
            }
        }
        return res;
    }
};
