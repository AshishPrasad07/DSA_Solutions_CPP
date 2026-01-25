/*
Problem: 3813. Vowel-Consonant Score

You are given a string s consisting of lowercase English letters, spaces, and digits.

Let v be the number of vowels in s and c be the number of consonants in s.  
A vowel is one of the letters 'a', 'e', 'i', 'o', or 'u', while any other letter 
in the English alphabet is considered a consonant.

The score of the string s is defined as:
- If c > 0, score = floor(v / c)
- Otherwise, score = 0

Return an integer denoting the score of the string.

Approach:
- Iterate through each character in the string:
    - Increment v if the character is a vowel.
    - Increment c if the character is a consonant.
- If there are no consonants, return 0.
- Otherwise, return floor(v / c).

Time Complexity:   O(n)
Space Complexity:  O(1)
*/

class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for(char& ch: s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                v++;
            }
            else if(isalpha(ch)){
                c++;
            }
        }
        if(c == 0){
            return 0;
        }
        return (int)floor(v / c);
    }
};
