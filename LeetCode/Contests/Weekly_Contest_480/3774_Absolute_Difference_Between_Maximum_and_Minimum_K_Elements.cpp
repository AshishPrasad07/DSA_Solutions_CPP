/*
Problem: 3774. Absolute Difference Between Maximum and Minimum K Elements

You are given an integer array 'nums' and an integer 'k'.

Find the absolute difference between:
- the sum of the k largest elements in the array, and
- the sum of the k smallest elements in the array.

Return an integer denoting this difference.

Approach:
- Sort the array in ascending order.
- Sum the first k elements for the smallest elements sum.
- Sum the last k elements for the largest elements sum.
- Return the absolute difference between these two sums.

Time Complexity: O(n log n), where n = nums.size()
Space Complexity: O(1)
*/

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int s1 = 0, s2 = 0;
        
        // Sum of k smallest elements
        for(int i = 0; i < k; i++){
            s1 += nums[i];
        }
        
        // Sum of k largest elements
        for(int i = nums.size() - k; i < nums.size(); i++){
            s2 += nums[i];
        }
        
        return abs(s1 - s2);
    }
};
