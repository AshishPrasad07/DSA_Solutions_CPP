/*
Problem: 3713. Longest Balanced Substring I

You are given a string 's' consisting of lowercase English letters.

A substring of 's' is called balanced if all distinct characters in the substring
appear the same number of times.

Return the length of the longest balanced substring of 's'.

Approach:
- Use a brute-force approach by checking all substrings.
- For each starting index 'i', maintain a frequency array of size 26.
- For each ending index 'j', update the frequency of the current character.
- After each update, check if the substring is balanced:
    - A substring is balanced if all non-zero frequencies are equal.
- Track and update the maximum balanced substring length.

Time Complexity:  O(n² * 26) ≈ O(n²)
Space Complexity: O(1), since frequency array size is constant (26)
*/

class Solution {
public:
    bool isBalanced(int freq[]) {
        int num = 0;  
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                if(num == 0){
                    num = freq[i];   // Set the reference frequency
                }
                if(num != freq[i]){  // Frequencies must match
                    return false;
                }
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++){
            int freq[26] = {0};  // Track character frequencies

            for(int j = i; j < n; j++){
                freq[s[j] - 'a']++;  // Update frequency

                if(isBalanced(freq)){  // Check balanced condition
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;  // Return longest balanced substring length
    }
};
