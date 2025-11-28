/*
Problem: 3745. Maximize Expression of Three Elements

You are given an integer array 'nums'.

Choose three elements a, b, and c from nums at distinct indices such that the value of the expression a + b - c is maximized.

Return an integer denoting the maximum possible value of this expression.

Approach:
- To maximize a + b - c, we want the two largest numbers as a and b and the smallest number as c.
- Sort the array.
- Pick the last two elements as a and b (largest two) and the first element as c (smallest).
- Compute the expression: nums[n-1] + nums[n-2] - nums[0].

Time Complexity: O(n log n) due to sorting
Space Complexity: O(1)
*/

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n - 1] + nums[n - 2] - nums[0];
    }
};
