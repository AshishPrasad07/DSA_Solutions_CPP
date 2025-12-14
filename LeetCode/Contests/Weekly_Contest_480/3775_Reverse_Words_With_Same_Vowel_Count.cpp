/*
Problem: 3775. Reverse Words With Same Vowel Count

You are given a string 's' consisting of lowercase English words, each separated by a single space.

Determine how many vowels appear in the first word. Then, reverse each following word that has the same vowel count. Leave all remaining words unchanged.

Return the resulting string.

Vowels are 'a', 'e', 'i', 'o', and 'u'.

Approach:
- Split the string into words using spaces as separators.
- Count the number of vowels in the first word.
- For each subsequent word, count its vowels:
    - If it matches the first word's vowel count, reverse the word.
    - Otherwise, leave it unchanged.
- Concatenate the words with spaces to form the resulting string.

Time Complexity: O(n), where n = length of the string
Space Complexity: O(n)
*/

class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string t;
        // Split string into words
        for(char ch: s){
            if(ch == ' '){
                v.push_back(t);
                t = "";
            }
            else{
                t.push_back(ch);
            }
        }
        if(!t.empty()){
            v.push_back(t);
        }

        // Count vowels in the first word
        int cnt = 0;
        for(char ch: v[0]){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                cnt++;
            }
        }

        // Reverse words matching the first word's vowel count
        for(int i = 1; i < v.size(); i++){
            int curr = 0;
            for(char ch: v[i]){
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    curr++;
                }
            }
            if(curr == cnt){
                reverse(v[i].begin(), v[i].end());
            }
        }

        // Concatenate words back into a string
        string res;
        for(int i = 0; i < v.size(); i++){
            for(char ch: v[i]){
                res.push_back(ch);
            }
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};
