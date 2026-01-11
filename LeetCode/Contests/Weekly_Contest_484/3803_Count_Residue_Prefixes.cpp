/*
Problem: 3803. Count Residue Prefixes

You are given a string s consisting only of lowercase English letters.

A prefix of s is called a residue if the number of distinct characters
in the prefix is equal to len(prefix) % 3.

Return the count of residue prefixes in s.

Approach:
- Traverse the string from left to right.
- Maintain a hash map to store the frequency of characters in the current prefix.
- For each index, check if the number of distinct characters equals (current prefix length % 3).
- If the condition is satisfied, increment the count.

Time Complexity:   O(n)
Space Complexity:  O(1) (at most 26 characters stored)
*/

class Solution {
public:
    int residuePrefixes(string s) {
        unordered_map<char, int> mp;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            if (mp.size() == (i + 1) % 3) {
                cnt++;
            }
        }
        return cnt;
    }
};
