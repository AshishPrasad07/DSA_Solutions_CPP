/*
Problem: 3396. Minimum Number of Operations to Make Elements in Array Distinct

You are given an integer array nums. You need to ensure that the elements in the array are distinct.
To achieve this, you can perform the following operation any number of times:
- Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.
Note that an empty array is considered to have distinct elements.
Return the minimum number of operations needed to make the elements in the array distinct.

Approach:
- Start by iterating the array from the end (to make early termination easier).
- Use an unordered_map to track the frequency of each element.
- As soon as a duplicate is found, calculate the minimum number of operations required to make the array distinct.
  - If the current index is `i`, the minimum operations needed will be `i / 3 + 1`.
- If no duplicates are found, return 0.

Time Complexity: O(n), where n is the size of the array
Space Complexity: O(n), due to the unordered_map storing element frequencies
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();  // Get the size of the input array
        unordered_map<int, int> mp;  // To store frequencies of elements

        // Iterate through the array from the end to the start
        for (int i = n - 1; i >= 0; i--) {
            mp[nums[i]]++;  // Increment the frequency of the current element
            
            // If a duplicate is found, calculate the minimum number of operations
            if (mp[nums[i]] > 1) {
                return i / 3 + 1;  // Return the number of operations required
            }
        }

        // If no duplicates found, return 0 since the array is already distinct
        return 0;
    }
};
