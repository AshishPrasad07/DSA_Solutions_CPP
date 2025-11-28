/*
Problem: 3755. Find Maximum Balanced XOR Subarray Length

Given an integer array nums, return the length of the longest subarray that:
- Has a bitwise XOR of zero.
- Contains an equal number of even and odd numbers.

Return 0 if no such subarray exists.

Approach:
- Use prefix XOR to track XOR of subarrays.
- Maintain a running difference (diff) between count of even and odd numbers.
- Combine prefix XOR and diff into a single key to detect previously seen states.
- Use a hashmap to store the earliest index of each combined key.
- If a key repeats, the subarray between previous index + 1 and current index
  satisfies both conditions. Update the maximum length.

Time Complexity: O(n) — where n = size of the array
Space Complexity: O(n) — 
*/

class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> mp;  // Map from combined key to earliest index
        int prefix = 0;                     // Prefix XOR
        int diff = 0;                       // Difference between even and odd counts
        int res = 0;                        

        long long k = ((long long)0 << 32) ^ (long long)0;  // Initial combined key
        mp[k] = -1;  // Base case for empty prefix

        for(int i = 0; i < n; i++){
            prefix ^= nums[i];               // Update prefix XOR
            if(nums[i] % 2 == 0){
                diff++;                      // Even number
            } else {
                diff--;                      // Odd number
            }

            // Combine prefix XOR and diff into a single 64-bit key
            long long currK = ((long long)prefix << 32) ^ (long long)(diff);

            if(mp.find(currK) != mp.end()){
                int len = i - mp[currK];    // Length of subarray with same state
                if(len > res){
                    res = len;              // Update maximum length
                }
            } else {
                mp[currK] = i;              // Store earliest occurrence
            }
        }

        return res;
    }
};
