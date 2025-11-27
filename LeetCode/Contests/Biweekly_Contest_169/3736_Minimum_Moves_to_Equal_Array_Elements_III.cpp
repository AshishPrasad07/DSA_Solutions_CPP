/*
Problem: 3736. Minimum Moves to Equal Array Elements III

You are given an integer array 'nums'.

In one move, you may increase the value of any single element nums[i] by 1.

Return the minimum total number of moves required so that all elements in nums become equal.

Approach:
- Find the maximum element in the array.
- For each element, calculate the difference between the maximum and that element.
- Sum up all differences to get the total moves needed.
- Each move increases one element by 1, so total moves = sum of (maxElem - nums[i]).

Time Complexity: O(n), where n = nums.size()
Space Complexity: O(1)
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxElem = 0;
        // Find the maximum element
        for(int num: nums){
            maxElem = max(maxElem, num);
        }

        int ans = 0;
        // Sum differences to compute moves
        for(int num: nums){
            ans += (maxElem - num);
        }

        return ans;
    }
};
