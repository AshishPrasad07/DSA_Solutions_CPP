/*
Problem: 3737. Count Subarrays With Majority Element I

You are given an integer array 'nums' and an integer 'target'.

Return the number of subarrays of 'nums' in which 'target' is the majority element.

The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

Approach:
- Iterate through all possible subarrays using two nested loops.
- Maintain a frequency count of 'target' in the current subarray.
- For each subarray, check if target appears more than half the length of the subarray.
- If yes, increment the count.
- Return the total count at the end.

Time Complexity: O(n^2), where n = nums.size()
Space Complexity: O(1)
*/

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt = 0;
        int n = nums.size();

        // Iterate over all subarrays
        for(int i = 0; i < n; i++){
            int freq = 0; // frequency of target in current subarray
            for(int j = i; j < n; j++) {
                if(nums[j] == target){
                    freq++;
                }
                // Check if target is majority
                if(freq > (j - i + 1) / 2){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
