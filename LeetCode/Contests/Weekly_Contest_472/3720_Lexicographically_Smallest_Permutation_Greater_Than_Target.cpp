/*
Problem: 3720. Lexicographically Smallest Permutation Greater Than Target

You are given two strings 's' and 'target', both of length n, consisting of lowercase English letters.

Return the lexicographically smallest permutation of 's' that is strictly greater than 'target'. 
If no permutation exists, return an empty string.

Approach:
- Count the frequency of each character in 's'.
- Use a recursive backtracking function to build the result:
    * At each index i, try available characters in lexicographical order.
    * Use 'flag' to indicate if the prefix so far is already greater than target.
    * If 'flag' is true, pick any remaining character; else pick only characters >= target[i].
- Return the first valid permutation found, or "" if none exists.

Time Complexity:
- Theoretical worst-case: O(26^N) (all letters distinct and no pruning).
- Practical runtime: O(N × D) for typical LeetCode inputs due to repeated letters and pruning,
  where N = s.length, D ≤ 26 = number of distinct letters.

Space Complexity: O(N) for recursion stack and result string.
*/

class Solution {
public:
    bool func(int i, int n, string& target, int freq[], string& res, bool flag){
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(freq[ch - 'a'] == 0) continue;

            bool use = flag || ch >= target[i]; // Decide if character can be used
            if(!use) continue;

            res.push_back(ch);
            freq[ch - 'a']--;

            bool next = flag || ch > target[i]; // Update flag if prefix exceeds target

            if(i + 1 == n){
                if(next) return true; // Found valid permutation
            }
            else if(func(i + 1, n, target, freq, res, next)){
                return true; // Recurse
            }

            res.pop_back(); // Backtrack
            freq[ch - 'a']++;
        }
        return false; // No valid permutation found at this level
    }

    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        int freq[26] = {0};
        for(char ch: s) freq[ch - 'a']++; // Count character frequencies

        string res;
        if(func(0, n, target, freq, res, false)){
            return res;
        }

        return ""; // No permutation greater than target exists
    }
};
