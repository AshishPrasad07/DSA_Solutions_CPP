/*
Problem: 3819. Rotate Non-Negative Elements

You are given an integer array nums and an integer k. Rotate only the non-negative 
elements of the array to the left by k positions in a cyclic manner. Negative elements 
must remain in their original positions.

Approach:
- Extract all non-negative elements into a separate list.
- Perform a cyclic left rotation by k positions using modulo arithmetic.
- Place the rotated elements back into their original non-negative positions.
- Negative elements remain fixed.

Time Complexity:   O(n)
Space Complexity:  O(n)
*/

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pos;
        for(int num: nums){
            if(num >= 0){
                pos.push_back(num);
            }
        }
        if(pos.size() == 0){
            return nums;
        }
        vector<int> newpos(pos);
        k = k % pos.size();
        for(int i = 0; i < pos.size(); i++){
            int idx = (i - k + pos.size()) % pos.size();
            newpos[idx] = pos[i];
        }
        int j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                continue;
            }
            nums[i] = newpos[j];
            j++;
        }
        return nums;
    }
};
