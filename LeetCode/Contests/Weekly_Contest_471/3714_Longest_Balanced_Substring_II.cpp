/*
Problem: 3714. Longest Balanced Substring II

You are given a string 's' consisting only of the characters 'a', 'b', and 'c'.

A substring of 's' is called balanced if all distinct characters in the substring
appear the same number of times.

Return the length of the longest balanced substring of 's'.

Approach:
We handle all possible cases based on how many distinct characters appear in the substring:

1. One Character Case:
   - If a substring contains only one character ('a', 'b', or 'c'), it is always balanced.
   - We compute the longest consecutive run of each single character.

2. Two Character Case:
   - For the character pairs ('a','b'), ('a','c'), ('b','c'):
       * Use prefix differences: countA - countB.
       * If the same difference appears again at a later index, the substring between those indices
         has equal counts of the two characters.
       * Reset when encountering the third character.

3. Three Character Case:
   - Use two prefix differences:
       diff1 = countA - countB
       diff2 = countA - countC
   - Store the earliest index for each (diff1, diff2) pair.
   - If the same pair appears again, the substring between them is balanced.

Time Complexity:
- O(n) overall.

Space Complexity:
- O(n) in the worst case due to storing prefix differences.
*/

class Solution {
public:
    // Handle case with exactly two distinct characters
    int twoChar(char a, char b, const string& s) {
        int n = s.size();
        int countA = 0, countB = 0;
        unordered_map<int, int> mp;
        mp[0] = -1; // Initialize prefix difference map

        int maxLen = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != a && s[i] != b){
                // Reset counts and map if a third character is encountered
                countA = countB = 0;
                mp.clear();
                mp[0] = i;
            } else {
                if(s[i] == a) countA++;
                else if(s[i] == b) countB++;

                int diff = countA - countB;

                // If we have seen this difference before, update maxLen
                if(mp.find(diff) != mp.end()){
                    maxLen = max(maxLen, i - mp[diff]);
                } else {
                    mp[diff] = i; // Store first occurrence of this difference
                }
            }
        }
        return maxLen;
    }

    // Handle case with all three characters
    int threeChar(const string& s) {
        int n = s.size();
        int countA = 0, countB = 0, countC = 0;
        int maxLen = 0;

        map<pair<int,int>, int> mp;
        mp[{0,0}] = -1; // Initialize map for pair differences

        for(int i = 0; i < n; i++){
            if(s[i] == 'a') countA++;
            else if(s[i] == 'b') countB++;
            else countC++;

            int diff1 = countA - countB;
            int diff2 = countA - countC;

            pair<int,int> key = {diff1, diff2};

            // If this pair of differences was seen before, update maxLen
            if(mp.find(key) != mp.end()){
                maxLen = max(maxLen, i - mp[key]);
            } else {
                mp[key] = i; // Store first occurrence
            }
        }
        return maxLen;
    }

    // Handle case with only one character
    int oneChar(char ch, const string& s) {
        int len = 0, maxLen = 0;
        for(char c: s){
            if(c == ch){
                len++;
                maxLen = max(maxLen, len); // Update max consecutive length
            } else {
                len = 0; // Reset when different character encountered
            }
        }
        return maxLen;
    }

    // Main function to find the longest balanced substring
    int longestBalanced(string s) {
        int maxLen = 0;

        // Check one character cases
        maxLen = max(maxLen, oneChar('a', s));
        maxLen = max(maxLen, oneChar('b', s));
        maxLen = max(maxLen, oneChar('c', s));

        // Check two character cases
        maxLen = max(maxLen, twoChar('a', 'b', s));
        maxLen = max(maxLen, twoChar('a', 'c', s));
        maxLen = max(maxLen, twoChar('b', 'c', s));

        // Check three character case
        maxLen = max(maxLen, threeChar(s));

        return maxLen;
    }
};
