/*
Problem: 3779. Minimum Number of Operations to Have Distinct Elements

You are given an integer array nums.

In one operation, you remove the first three elements of the current array.
If there are fewer than three elements remaining, all remaining elements are removed.

Repeat this operation until the array is empty or contains no duplicate values.

Return an integer denoting the number of operations required.

Approach:
- Use a frequency map to count occurrences of each element.
- Start checking from the end of the array to see if any element has frequency > 1.
- Maintain a pointer k representing how many elements have already been removed from the front.
- While a duplicate exists, remove the next group of up to three elements from the front:
  - Decrease their frequency in the map.
  - Remove elements from the map when their frequency becomes zero.
- Increment the operation count for each removal.
- Continue until no duplicates remain or the array becomes empty.

Time Complexity:   O(n)
Space Complexity:  O(n)
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }

        int res = 0;
        int k = 0;
        int n = nums.size();

        for(int i = n - 1; i >= 0 && k <= i; i--){
            while(mp[nums[i]] > 1){
                for(int j = k; j < k + 3 && j <= i; j++){
                    mp[nums[j]]--;
                    if(mp[nums[j]] == 0){
                        mp.erase(nums[j]);
                    }
                }
                k += 3;
                res++;
            }
        }
        return res;
    }
};
