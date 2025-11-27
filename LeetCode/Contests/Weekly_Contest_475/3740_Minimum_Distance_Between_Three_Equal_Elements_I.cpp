/*
Problem: 3740. Minimum Distance Between Three Equal Elements I

You are given an integer array 'nums'.

A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.

Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

Approach:
- Iterate through all possible triplets (i, j, k) with i < j < k.
- Check if nums[i] == nums[j] == nums[k].
- If yes, calculate the distance as abs(i-j) + abs(j-k) + abs(k-i).
- Keep track of the minimum distance found.
- Return the minimum distance, or -1 if no valid triplet exists.

Time Complexity: O(n^3), where n = nums.size()
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int res = -1;
        int n = nums.size();

        // Iterate through all triplets
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if(nums[i] == nums[j] && nums[j] == nums[k]){
                        int dis = abs(i - j) + abs(j - k) + abs(k - i);
                        if(res == -1){
                            res = dis;
                        } else {
                            res = min(res, dis);
                        }
                    }
                }
            }
        }

        return res;
    }
};
