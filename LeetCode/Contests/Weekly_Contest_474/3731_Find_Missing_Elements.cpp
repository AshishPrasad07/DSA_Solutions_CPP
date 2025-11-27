/*
Problem: 3731. Find Missing Elements

You are given an integer array 'nums' consisting of unique integers.
Originally, nums contained every integer within a certain range, 
but some integers might have gone missing. The smallest and largest 
integers of the original range are still present in nums.

Return a sorted list of all the missing integers in this range. 
If no integers are missing, return an empty list.

Approach:
- Sort the input array to get the numbers in order.
- Use an unordered_map to mark all present numbers.
- Iterate from the smallest number to the largest number:
    * If a number is not present in the map, add it to the result.
- Return the result vector.

Time Complexity: O(n log n + R), where n = nums.size() and R = range of numbers
Space Complexity: O(n) for the map and result vector
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array
        vector<int> res;
        int n = nums.size();

        // Mark present numbers
        unordered_map<int, int> mp;
        for(int num : nums) {
            mp[num] = 1;
        }

        int num1 = nums[0], num2 = nums[n - 1];

        // Iterate from smallest to largest number
        for(int i = 0; i < n; i++){
            if(nums[i] != num1){
                while(true){
                    if(num1 > num2) break;
                    if(mp.find(num1) == mp.end()){ // If number is missing
                        res.push_back(num1);
                    }
                    num1++;
                }
                break;
            }
            num1++;
        }

        return res;
    }
};
