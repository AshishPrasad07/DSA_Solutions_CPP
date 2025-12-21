/*
Problem: 3780. Maximum Sum of Three Numbers Divisible by Three

You are given an integer array nums.

Your task is to choose exactly three integers from nums such that their sum is divisible by three.

Return the maximum possible sum of such a triplet. If no such triplet exists, return 0.

Approach:
- Group all numbers based on their remainder when divided by 3 (0, 1, 2).
- Sort each group in descending order to easily pick the largest values.
- Check all valid combinations of three numbers whose sum is divisible by 3:
  - Three numbers from the same remainder group (0+0+0, 1+1+1, 2+2+2).
  - One number from each remainder group (0+1+2).
- Compute the maximum possible sum among all valid combinations.
- If no valid triplet exists, return 0.

Time Complexity:   O(n log n)
Space Complexity:  O(n)
*/

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> mods[3];
        for(int num : nums){
            mods[num % 3].push_back(num);
        }

        int res = 0;

        for(int i = 0; i < 3; i++){
            sort(mods[i].rbegin(), mods[i].rend());
        }

        if(mods[0].size() >= 3){
            res = max(res, mods[0][0] + mods[0][1] + mods[0][2]);
        }
        if(mods[1].size() >= 3){
            res = max(res, mods[1][0] + mods[1][1] + mods[1][2]);
        }
        if(mods[2].size() >= 3){
            res = max(res, mods[2][0] + mods[2][1] + mods[2][2]);
        }
        if(!mods[0].empty() && !mods[1].empty() && !mods[2].empty()){
            res = max(res, mods[0][0] + mods[1][0] + mods[2][0]);
        }

        return res;
    }
};
