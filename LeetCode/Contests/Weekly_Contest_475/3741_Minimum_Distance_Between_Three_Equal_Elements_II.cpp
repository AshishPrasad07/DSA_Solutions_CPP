/*
Problem: 3741. Minimum Distance Between Three Equal Elements II

You are given an integer array 'nums'.

A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.

Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

Approach:
- Use two hash maps to track the last two occurrences of each number:
    - mp1[num] = second last occurrence
    - mp2[num] = last occurrence
- For each element nums[i]:
    - If it is the third or later occurrence, compute the distance using the two previous indices.
    - Update mp1 and mp2 to shift the last two occurrences.
- Keep track of the minimum distance across all numbers.
- Return -1 if no valid triplet exists.

Time Complexity: O(n), where n = nums.size()
Space Complexity: O(n), for the hash maps
*/

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int res = -1;
        unordered_map<int, int> mp1, mp2;

        for(int i = 0; i < n; i++){
            if(mp1.find(nums[i]) == mp1.end()){
                // First occurrence
                mp1[nums[i]] = i;
            }
            else if(mp2.find(nums[i]) == mp2.end()){
                // Second occurrence
                mp2[nums[i]] = i;
            }
            else{
                // Third or later occurrence: calculate distance
                int dis = abs(mp1[nums[i]] - mp2[nums[i]]) + abs(mp2[nums[i]] - i) + abs(i - mp1[nums[i]]);
                if(res == -1 || dis < res){
                    res = dis;
                }
                // Update last two occurrences
                mp1[nums[i]] = mp2[nums[i]];
                mp2[nums[i]] = i;
            }
        }

        return res;
    }
};
