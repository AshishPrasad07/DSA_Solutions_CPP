/*
Problem: 3732. Maximum Product of Three Elements After One Replacement

You are given an integer array 'nums'.
You must replace exactly one element in the array with any integer value in the range [-10^5, 10^5] (inclusive).

After performing this single replacement, determine the maximum possible product of any three elements at distinct indices from the modified array.

Return an integer denoting the maximum product achievable.

Approach:
- Track the three largest and three smallest numbers in the array.
- Consider replacing one element with either 100000 or -100000 to maximize the product.
- Compute all possible products using the top 2 or 3 largest/smallest numbers combined with the replacement.
- Keep updating the maximum result among all these candidate products.

Time Complexity: O(n) — single pass through the array
Space Complexity: O(1) — only a few variables used
*/

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long res = LLONG_MIN;

        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for(int num: nums){
            // Update largest 3 numbers
            if(num > max1){
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if(num > max2){
                max3 = max2;
                max2 = num;
            }
            else if(num > max3){
                max3 = num;
            }

            // Update smallest 3 numbers
            if(num < min1){
                min3 = min2;
                min2 = min1;
                min1 = num;
            }
            else if(num < min2){
                min3 = min2;
                min2 = num;
            }
            else if(num < min3){
                min3 = num;
            }
        }

        // Consider all candidate products after replacement
        if(res < (long long)100000 * max1 * max2) res = (long long)100000 * max1 * max2;
        if(res < (long long)100000 * min1 * min2) res = (long long)100000 * min1 * min2;
        if(res < (long long)-100000 * min1 * min2) res = (long long)-100000 * min1 * min2;
        if(res < (long long)-100000 * max1 * max2) res = (long long)-100000 * max1 * max2;
        if(res < (long long)-100000 * max1 * max3) res = (long long)-100000 * max1 * max3;
        if(res < (long long)-100000 * min1 * min3) res = (long long)-100000 * min1 * min3;
        if(res < (long long)100000 * max1 * max3) res = (long long)100000 * max1 * max3;
        if(res < (long long)100000 * min1 * min3) res = (long long)100000 * min1 * min3;
        if(res < (long long)100000 * max1 * min1) res = (long long)100000 * max1 * min1;
        if(res < (long long)-100000 * max1 * min1) res = (long long)-100000 * max1 * min1;

        return res;
    }
};
