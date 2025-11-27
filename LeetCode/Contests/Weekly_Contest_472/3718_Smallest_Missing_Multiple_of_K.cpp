/*
Problem: 3718. Smallest Missing Multiple of K

Given an integer array 'nums' and an integer 'k', return the smallest positive multiple of 'k' 
that is missing from 'nums'.

A multiple of 'k' is any positive integer divisible by 'k'.

Approach:
- Use an unordered_map to store all numbers present in 'nums'.
- Iterate over positive multiples of k (k, 2k, 3k, ...) and check if each is in the map.
- Return the first multiple that is missing.

Time Complexity: O(n + m), where n = size of nums and m is the smallest missing multiple (practically efficient)
Space Complexity: O(n)
*/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        // Store all numbers in a map for O(1) lookup
        for(int num: nums){
            mp[num] = 1;
        }

        int i = 1;
        // Check multiples of k one by one
        while(true){
            if(mp.find(k * i) == mp.end()){
                return k * i; // Return the first missing multiple
            }
            i++;
        }

        return 0; // Unreachable, added for completeness
    }
};
