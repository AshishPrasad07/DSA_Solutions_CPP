/*
Problem: 3794. Reverse String Prefix

You are given a string s and an integer k.  

Reverse the first k characters of s and return the resulting string.

Approach:
- Use the built-in reverse function to reverse the first k characters.
- This allows reversing directly without extra loops.
- Return the modified string.

Time Complexity:   O(k)
Space Complexity:  O(1)
*/

class Solution {
public:
    string reversePrefix(string s, int k) {
        reverse(s.begin(), s.begin() + k);
        return s;
    }
};
