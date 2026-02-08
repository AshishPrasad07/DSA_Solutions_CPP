/*
Problem: 3835. Count Subarrays With Cost Less Than or Equal to K

You are given an integer array nums and integer k.  
For any subarray nums[l..r], cost = (max(nums[l..r]) - min(nums[l..r])) * (r - l + 1).  
Return the number of subarrays whose cost ≤ k.

Approach:
- Use sliding window with two monotonic deques to maintain min and max efficiently.  
- Store indexes in the deques to handle duplicates and remove elements when window moves.  
- Expand the right pointer, shrink left when cost exceeds k.  
- For each valid window, add its length to the result (counts all subarrays ending at current index).

Time Complexity:   O(n)  
Space Complexity:  O(n)
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int> minDeque, maxDeque;
        long long res = 0;
        int i = 0, n = nums.size();
        for(int j = 0; j < n; j++){
            while(!maxDeque.empty() && nums[maxDeque.back()] <= nums[j]) maxDeque.pop_back();
            maxDeque.push_back(j);
            while(!minDeque.empty() && nums[minDeque.back()] >= nums[j]) minDeque.pop_back();
            minDeque.push_back(j);
            while((long long)(nums[maxDeque.front()] - nums[minDeque.front()]) * (j - i + 1) > k){
                if(maxDeque.front() == i) maxDeque.pop_front();
                if(minDeque.front() == i) minDeque.pop_front();
                i++;
            }
            res += (j - i + 1);
        }
        return res;
    }
};
