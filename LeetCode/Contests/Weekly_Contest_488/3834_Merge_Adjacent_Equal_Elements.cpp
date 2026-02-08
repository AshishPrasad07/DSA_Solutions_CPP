/*
Problem: 3834. Merge Adjacent Equal Elements

You are given an integer array nums.  
Repeatedly apply the following merge operation until no more changes:  
- If two adjacent elements are equal, replace them with a single element equal to their sum.  
Return the final array after all possible merges.

Approach:
- Use a stack to simulate the merge process efficiently.  
- Traverse the array:
    - If current element equals the top of the stack, merge them (sum).  
    - Continue merging if the new value equals the next top (cascading merges).  
- Push non-merging elements to the stack.  
- Reconstruct the final array from the stack in correct order.

Time Complexity:   O(n)  
Space Complexity:  O(n)
*/

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> res;
        for(int i = 0; i < nums.size(); i++){
            if(!res.empty() && res.top() == nums[i]){
                long long num = res.top() + nums[i]; res.pop();
                while(!res.empty() && res.top() == num){ num += res.top(); res.pop(); }
                res.push(num);
            } else {
                res.push(nums[i]);
            }
        }
        vector<long long> ans;
        while(!res.empty()){ ans.push_back(res.top()); res.pop(); }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
