/*
Problem: 3719. Longest Balanced Subarray I

You are given an integer array 'nums'.

A subarray is called balanced if the number of distinct even numbers in the subarray
is equal to the number of distinct odd numbers.

Return the length of the longest balanced subarray.

Approach:
- Use a brute-force approach to check all subarrays.
- For each starting index 's', maintain two sets:
    * 'even' to store distinct even numbers
    * 'odd' to store distinct odd numbers
- For each ending index 'e', add nums[e] to the appropriate set.
- If the size of 'even' equals the size of 'odd', update the maximum length.
- Return the maximum balanced subarray length.

Time Complexity: O(n^2), where n = size of nums
Space Complexity: O(n) for storing sets
*/

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for(int s = 0; s < n; s++){
            unordered_set<int> even, odd; // Track distinct even and odd numbers

            for(int e = s; e < n; e++){
                if(nums[e] % 2 == 0){
                    even.insert(nums[e]); // Add even number
                }
                else{
                    odd.insert(nums[e]);  // Add odd number
                }

                if(even.size() == odd.size()){
                    maxLen = max(maxLen, e - s + 1); // Update max length if balanced
                }
            }
        }

        return maxLen; // Return longest balanced subarray length
    }
};
