/*
Problem: 3379. Transformed Array
Platform: LeetCode
Contest: Weekly Contest 427
Description:
You are given an integer array nums representing a circular array. 
For each index i, move nums[i] steps right if positive, left if negative, 
or leave it if zero, and set the result array with the value at landing index.
*/

// Time Complexity:  O(N)
// Space Complexity: O(N)
// N = Length of Array
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0); // Result array initialized with 0s

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                // Move nums[i] steps to the right in circular manner
                int index = (i + nums[i]) % n;
                ans[i] = nums[index];
            } 
            else if(nums[i] < 0){
                // Move |nums[i]| steps to the left in circular manner
                int index = (nums[i] % n + n + i) % n;
                ans[i] = nums[index];
            } 
            else{
                // nums[i] == 0, leave as is
                ans[i] = nums[i];
            }
        }

        return ans;
    }
};
