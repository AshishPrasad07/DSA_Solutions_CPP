/*
Problem: 3833. Count Dominant Indices

You are given an integer array nums of length n.  
An element at index i is called dominant if:  
nums[i] > average(nums[i + 1], nums[i + 2], ..., nums[n - 1])  

Return the number of dominant indices.  
Note: The rightmost element of the array is never dominant.

Approach:
- Compute the total sum of the array.  
- Iterate from left to right while maintaining the suffix sum.  
- For each index, check if nums[i] > (sum of remaining elements / number of elements).  
- Count the number of indices satisfying the condition.

Time Complexity:   O(n)  
Space Complexity:  O(1)
*/

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum = 0, n = nums.size(), res = 0;
        for(int num: nums) sum += num;
        for(int i = 0; i < n - 1; i++){
            sum -= nums[i];
            if(nums[i] > (double)(sum / (n - i - 1))) res++;
        }
        return res;
    }
};
