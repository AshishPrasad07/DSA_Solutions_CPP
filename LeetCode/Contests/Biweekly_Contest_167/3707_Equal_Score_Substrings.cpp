/*
Problem: 3707. Equal Score Substrings

You are given a string 's' consisting of lowercase English letters.  
The score of a string is the sum of the positions of its characters in the alphabet, where 
'a' = 1, 'b' = 2, ..., 'z' = 26.

Determine whether there exists an index 'i' such that the string can be split into two non-empty substrings 
's[0..i]' and 's[(i + 1)..(n - 1)]' that have equal scores. 
Return 'true' if such a split exists, otherwise return 'false'.

Approach:
- First, calculate the total score of the string by summing the positions of each character.
- Then, iterate through the string maintaining a cumulative score of the left substring 's[0..i]'.
- If the cumulative score at any index 'i' equals half of the total score, it means we can split the string into two equal-score substrings.
- Return 'true' if such a split is found; otherwise, return 'false'.

Time Complexity: O(n), where n = length of string s
Space Complexity: O(1)
*/

class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();  // Get the length of the string
        
        // Step 1: Calculate the total score of the entire string
        int totalScore = 0;
        for(char ch: s) {
            totalScore += (ch - 'a' + 1);  // Add each character's score to totalScore
        }

        // Step 2: Maintain a cumulative score for the substring 's[0..i]'
        int currScore = 0;
        for(int i = 0; i < n; i++) {
            currScore += (s[i] - 'a' + 1);  // Add the score of the current character to currScore
            
            // Step 3: If 2 * currScore equals the totalScore, return true (split point found)
            if(2 * currScore == totalScore) {
                return true;
            }
        }
        
        // Step 4: Return false if no valid split is found
        return false;
    }
};
