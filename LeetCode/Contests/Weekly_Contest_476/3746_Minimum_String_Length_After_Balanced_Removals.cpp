/*
Problem: 3746. Minimum String Length After Balanced Removals

You are given a string 's' consisting only of the characters 'a' and 'b'.

You are allowed to repeatedly remove any substring where the number of 'a' characters 
is equal to the number of 'b' characters. After each removal, the remaining parts of 
the string are concatenated together without gaps.

Return an integer denoting the minimum possible length of the string after performing 
any number of such operations.

Approach:
- Each balanced substring has an equal number of 'a's and 'b's.
- Removing balanced substrings repeatedly ultimately leaves only the absolute difference 
  between the number of 'a's and 'b's in the string.
- Count the number of 'a's minus the number of 'b's while iterating through the string.
- Return the absolute value of this count as the minimum length.

Time Complexity: O(n), where n = s.length()
Space Complexity: O(1)
*/

class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int count = 0;
        for(char ch: s){
            if(ch == 'a'){
                count++;
            }
            else{
                count--;
            }
        }
        return abs(count);
    }
};
