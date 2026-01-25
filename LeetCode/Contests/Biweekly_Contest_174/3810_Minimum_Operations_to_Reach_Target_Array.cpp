/*
Problem: 3810. Minimum Operations to Reach Target Array

You are given two integer arrays nums and target, each of length n, where nums[i] is the 
current value at index i and target[i] is the desired value at index i.

You may perform the following operation any number of times:
- Choose an integer value x.
- Find all maximal contiguous segments where nums[i] == x.
- For each segment, simultaneously update nums[l..r] to match target[l..r].

Return the minimum number of operations required to make nums equal to target.

Approach:
- Iterate through the array and identify all values in nums that differ from target.
- Count each unique value that needs to be changed; each corresponds to one operation.
- Return the total number of unique values that require operations.

Time Complexity:   O(n)
Space Complexity:  O(n) for the hash map
*/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            if(nums[i] != target[i]){
                mp[nums[i]]++;
            }
        }
        return mp.size();
    }
};
