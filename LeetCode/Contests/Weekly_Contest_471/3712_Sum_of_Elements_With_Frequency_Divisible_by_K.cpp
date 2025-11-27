/*
Problem: 3712. Sum of Elements With Frequency Divisible by K

You are given an integer array 'nums' of size n and an integer 'k'.  
Return the sum of all elements in 'nums' whose frequency is divisible by k.  
An element is included in the sum exactly as many times as it appears in the array if its total frequency is divisible by k.

Approach:
- Count the frequency of each element in 'nums' using an unordered_map.
- Iterate through the map:
    - If an element's frequency is divisible by k, add element * frequency to the sum.
- Return the total sum.

Time Complexity:  O(n), where n = size of the array
Space Complexity: O(n)
*/

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;  // Count frequencies of each number
        for(int num: nums){
            mp[num]++;
        }

        long long int sum = 0;  // Initialize sum

        for(auto m: mp){
            if(m.second % k == 0){  // If frequency divisible by k
                sum += (m.second * m.first);  // Add element * frequency to sum
            }
        }

        return sum;  // Return the final sum
    }
};
