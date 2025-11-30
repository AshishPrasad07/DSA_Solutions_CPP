/*
Problem: 3760. Maximum Substrings With Distinct Start

You are given a string s consisting of lowercase English letters.

Return an integer denoting the maximum number of substrings you can split s into such that each substring starts with a distinct character (i.e., no two substrings start with the same character).

Approach:
- Maintain a frequency array for 26 lowercase letters.
- Iterate through the string.
- Count each character the first time it appears as a start of a substring.
- The total count of distinct starting characters gives the answer.

Time Complexity: O(n)
Space Complexity: O(26) → O(1)
*/

class Solution {
public:
    int maxDistinct(string s) {
        int freq[26] = {0}; // Frequency array for 26 letters
        int count = 0;      // Number of distinct starting characters

        for(char ch: s){
            // If this character hasn't appeared before
            if(freq[ch - 'a'] == 0){
                freq[ch - 'a'] = 1; // Mark as seen
                count++;            // Increment distinct count
            }
        }

        return count; // Return total distinct starting characters
    }
};
