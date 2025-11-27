/*
Problem: 3738. Longest Non-Decreasing Subarray After Replacing at Most One Element

You are given an integer array 'nums'.

You are allowed to replace at most one element in the array with any other integer value of your choice.

Return the length of the longest non-decreasing subarray that can be obtained after performing at most one replacement.

An array is said to be non-decreasing if each element is greater than or equal to its previous one (if it exists).

Approach:
- Use two auxiliary arrays:
    - left[i] stores the length of the longest non-decreasing subarray ending at i.
    - right[i] stores the length of the longest non-decreasing subarray starting at i.
- Compute left[] and right[] with a single pass each.
- The maximum non-decreasing subarray length after at most one replacement can be:
    1. The original left[i] (no replacement needed)
    2. By "removing/replacing" nums[i], connecting left[i-1] and right[i+1] if possible.
- Handle edge cases when i is the first or last element.
- Return the maximum length found.

Time Complexity: O(n), where n = nums.size()
Space Complexity: O(n)
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }

        vector<int> left(n, 1), right(n, 1);

        // Compute lengths of non-decreasing subarrays ending at i
        for(int i = 1; i < n; i++){
            if(nums[i] >= nums[i - 1]){
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }

        // Compute lengths of non-decreasing subarrays starting at i
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] <= nums[i + 1]){
                right[i] = right[i + 1] + 1;
            } else {
                right[i] = 1;
            }
        }

        int maxLen = 1;

        // Case 1: no replacement, just original left[i]
        for(int i = 0; i < n; i++){
            maxLen = max(maxLen, left[i]);
        }

        // Case 2: replacing at most one element
        for(int i = 0; i < n; i++){
            int curr;
            if(i == 0){
                curr = 1 + right[1]; // replace first element
            }
            else if(i == n - 1){
                curr = 1 + left[n - 2]; // replace last element
            }
            else{
                int l = left[i - 1];
                int r = right[i + 1];
                if(nums[i - 1] <= nums[i + 1]){
                    curr = l + 1 + r; // connect left and right around replacement
                }
                else{
                    curr = max(l + 1, r + 1); // cannot connect, pick max
                }
            }
            maxLen = max(maxLen, curr);
        }

        return maxLen;
    }
};
