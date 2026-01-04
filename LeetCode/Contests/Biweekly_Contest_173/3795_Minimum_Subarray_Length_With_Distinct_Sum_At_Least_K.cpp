/*
Problem: 3795. Minimum Subarray Length With Distinct Sum At Least K

You are given an integer array nums and an integer k.  

Return the minimum length of a subarray whose sum of distinct values is at least k. If no such subarray exists, return -1.

Approach:
- Use a sliding window to iterate through the array.
- Maintain a map to track the count of each number in the current window.
- Maintain the sum of distinct elements in the window.
- Expand the window to the right, adding new elements.
- Shrink the window from the left whenever the sum >= k to minimize length.
- Return the minimum window length found, or -1 if none exists.

Time Complexity:   O(n)
Space Complexity:  O(n)
*/

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int res = -1;
        int sum = 0, i = 0;
        for(int j = 0; j < n; j++){
            if(mp[nums[j]] == 0){
                sum += nums[j];
            }
            mp[nums[j]]++;
            while(sum >= k){
                if(res == -1 || res > j - i + 1){
                    res = j - i + 1;
                }
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    sum -= nums[i];
                }
                i++;
            }
        }
        return res;
    }
};
