/*
Problem: 3784. Minimum Deletion Cost to Make All Characters Equal

You are given a string s of length n and an integer array cost of the same length, where cost[i] is the cost to delete the ith character of s.

You may delete any number of characters from s (possibly none), such that the resulting string is non-empty and consists of equal characters.

Return an integer denoting the minimum total deletion cost required.

Approach:
- Use a map to calculate the total cost for each character in the string.
- The idea is to keep all instances of one character and delete all others.
- Compute the sum of costs for all characters.
- For each character, calculate the cost to delete all other characters by subtracting its total cost from the sum.
- Return the minimum deletion cost among all characters.

Time Complexity:   O(n)
Space Complexity:  O(n)
*/

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = s.size();
        unordered_map<char, long long> mp;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            mp[s[i]] += cost[i];
            sum += cost[i];
        }

        long long res = sum;
        for(auto m : mp){
            if(res > sum - m.second){
                res = sum - m.second;
            }
        }

        return res;
    }
};
