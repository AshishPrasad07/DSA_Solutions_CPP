/*
Problem: 3823. Reverse Letters Then Special Characters in a String

You are given a string s consisting of lowercase English letters and special characters.

Approach:
- Separate letters and special characters into two lists.
- Reverse each list independently.
- Reconstruct the string by placing letters and special characters back in their original positions.

Time Complexity:   O(n)
Space Complexity:  O(n)
*/

class Solution {
public:
    string reverseByType(string s) {
        string letters, specials;
        for(char ch: s){
            if(isalpha(ch)) letters.push_back(ch);
            else specials.push_back(ch);
        }
        reverse(letters.begin(), letters.end());
        reverse(specials.begin(), specials.end());
        int li = 0, si = 0;
        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i])) s[i] = letters[li++];
            else s[i] = specials[si++];
        }
        return s;
    }
};
