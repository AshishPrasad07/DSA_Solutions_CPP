/*
Problem: 3804. Number of Centered Subarrays

You are given an integer array nums.

A subarray of nums is called centered if the sum of its elements is equal to at least one element within that same subarray.

Return the number of centered subarrays of nums.

Approach:
- Generate all possible subarrays.
- Maintain a running sum and a map of elements in the subarray.
- If the sum matches any element in the subarray, increment the count.

Time Complexity:   O(n^2)
Space Complexity:  O(n)
*/

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            unordered_map<int, int> mp;
            for (int j = i; j < n; j++) {
                mp[nums[j]]++;
                sum += nums[j];
                if (mp.find(sum) != mp.end()) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
