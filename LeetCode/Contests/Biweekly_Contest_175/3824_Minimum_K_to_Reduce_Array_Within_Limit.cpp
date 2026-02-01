/*
Problem: 3824. Minimum K to Reduce Array Within Limit

You are given a positive integer array nums.

For a positive integer k, define nonPositive(nums, k) as the minimum number of operations needed to make every element of nums non-positive. In one operation, you can choose an index i and reduce nums[i] by k.

Return an integer denoting the minimum value of k such that nonPositive(nums, k) <= k^2.

Approach:
- Use binary search to find the minimum value of k.
- For each candidate k, calculate the number of operations needed to make all elements non-positive using ceiling division.
- Check if the number of operations satisfies the condition (operations ≤ k^2) and adjust the search space accordingly.
- Handles edge cases such as arrays with all zeros or very large numbers.

Time Complexity:   O(n log(maxNum)), where maxNum is the maximum element in the array
Space Complexity:  O(1)
*/

class Solution {
public:
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int res = high;
        while(low <= high){
            int k = low + (high - low) / 2;
            long long curr = 0;
            for(int& num: nums){
                if(num > 0) curr += (num + k - 1) / k;
            }
            if(curr <= (long long)k * k){
                res = k;
                high = k - 1;
            }
            else low = k + 1;
        }
        return res;
    }
};
