/*
Problem: 3708. Longest Fibonacci Subarray

You are given an array of positive integers 'nums'.

A Fibonacci array is a contiguous sequence whose third and subsequent terms each equal the sum of the two preceding terms.

Return the length of the longest Fibonacci subarray in 'nums'.

Note: Subarrays of length 1 or 2 are always Fibonacci.

Approach:
- Step 1: If the length of the array is 2 or less, return the length of the array because any subarray of size 1 or 2 is automatically a Fibonacci subarray.
- Step 2: Initialize two variables:
    - 'currLen': keeps track of the current length of the Fibonacci subarray.
    - 'maxLen': keeps track of the longest Fibonacci subarray found so far.
- Step 3: Start iterating from index 2 (because the first two elements are always part of a Fibonacci subarray).
  - For each index 'i', check if the current element 'nums[i]' is the sum of the previous two elements ('nums[i-1]' and 'nums[i-2]').
  - If true, increment 'currLen' and update 'maxLen' with the larger of 'maxLen' and 'currLen'.
  - If false, reset 'currLen' to 2.
- Step 4: Return 'maxLen', which is the length of the longest Fibonacci subarray.

Time Complexity: O(n), where n is the length of the array `nums`
Space Complexity: O(1), since we are only using a few extra variables
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Handle base cases where the array has 2 or fewer elements
        if(n <= 2){
            return n;
        }
        
        int currLen = 2, maxLen = 2;  // Step 2: Initialize current length and max length
        
        // Step 3: Iterate through the array starting from index 2
        for(int i = 2; i < n; i++){
            // Check if current element is the sum of the previous two elements
            if(nums[i] == nums[i - 1] + nums[i - 2]){
                currLen++;  // If it forms a Fibonacci sequence, increment the length
                maxLen = max(maxLen, currLen);  // Update the maximum length found
            }
            else{
                currLen = 2;  // Reset length to 2 if it doesn't form a Fibonacci sequence
            }
        }
        
        // Step 4: Return the maximum length of the Fibonacci subarray
        return maxLen;
    }
};
