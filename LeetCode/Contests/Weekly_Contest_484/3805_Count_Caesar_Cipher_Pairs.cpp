/*
Problem: 3805. Count Caesar Cipher Pairs

You are given an array words of n strings. Each string has length m and contains only lowercase English letters.

Two strings s and t are similar if we can apply the following operation any number of times so that s and t become equal:
- Choose either s or t.
- Replace every letter in the chosen string with the next letter in the alphabet cyclically (next after 'z' is 'a').

Count the number of pairs of indices (i, j) such that:
- i < j
- words[i] and words[j] are similar.

Return the total number of such pairs.

Approach:
- Normalize each string by shifting it so that the first character becomes 'a'.
- Use a hash map to count occurrences of identical normalized strings.
- For each group of identical normalized strings, calculate the number of valid pairs using combination formula (nC2).
- Sum up the pairs from all groups to get the final result.

Time Complexity:   O(n * m)
Space Complexity:  O(n * m)
*/

class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long int res = 0;
        unordered_map<string, int> mp;

        for (string& s : words) {
            int shift = s[0] - 'a';
            for (char& ch : s) {
                ch = char((ch - 'a' - shift + 26) % 26 + 'a');
            }
            mp[s]++;
        }

        for (auto& m : mp) {
            long long t = m.second;
            res += ((long long)t * (t - 1) / 2);
        }

        return res;
    }
};
