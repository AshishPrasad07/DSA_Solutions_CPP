/*
Problem: 3761. Minimum Absolute Distance Between Mirror Pairs

You are given an integer array nums.

A mirror pair is a pair of indices (i, j) such that:
- 0 <= i < j < nums.length, and
- reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21.

Return the minimum absolute distance between the indices of any mirror pair. The absolute distance between indices i and j is abs(i - j).

If no mirror pair exists, return -1.

Approach:
- Create a helper function to reverse an integer.
- Use a hash map to store the last index of each number.
- Iterate from the end to the start:
    - Check if reversed number exists in the map.
    - Update minimum distance if a mirror pair is found.
- Return the minimum distance found, or -1 if none.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    // Helper function to reverse an integer
    int revInt(int x){
        int r = 0;
        while(x){
            r = r * 10 + (x % 10); // Append last digit to reversed number
            x /= 10;                // Remove last digit
        }
        return r;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; // Map to store last index of each number
        int count = -1;             // Initialize answer as -1 (no pair yet)

        // Iterate from end to start
        for(int i = n - 1; i >= 0; i--){
            int rev = revInt(nums[i]); // Reverse current number

            // Check if reversed number exists in map
            if(mp.find(rev) != mp.end()){
                // If first pair found
                if(count == -1){
                    count = abs(i - mp[rev]);
                }
                else if(count > abs(i - mp[rev])){
                    count = abs(i - mp[rev]); // Update minimum distance
                }
            }

            mp[nums[i]] = i; // Store current index in map
        }

        return count; // Return minimum distance or -1
    }
};
