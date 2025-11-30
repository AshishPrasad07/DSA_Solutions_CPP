/*
Problem: 3759. Count Elements With at Least K Greater Values

You are given an integer array nums of length n and an integer k.

An element in nums is said to be qualified if there exist at least k elements in the array that are strictly greater than it.

Return an integer denoting the total number of qualified elements in nums.

Approach:
- Handle edge cases first:
    - If k == 0, return nums.size() (all elements qualify)
    - If k > n, return 0 (no elements qualify)
- Sort a copy of the array.
- Count elements smaller than the k-th largest element.
- Iterate through nums and increment count for each element < nums[n-k] after sorting.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        // Edge case: k == 0, all elements qualify
        if(k == 0) return nums.size();
        // Edge case: k > size, no element qualifies
        if(k > nums.size()) return 0;

        // Make a copy of the array and sort it
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int count = 0;
        // Iterate through original array
        for(int i = 0; i < nums.size(); i++){
            // If element is less than k-th largest, it's qualified
            if(nums[i] < temp[nums.size() - k]){
                count++; // Increment count
            }
        }
        return count; // Return total count
    }
};
