/*
Problem: 3726. Remove Zeros in Decimal Representation

Given a positive integer n, return the integer obtained by removing all zeros from its decimal representation.

Approach:
- Convert the integer to a string for easy digit access.
- Initialize a result variable res = 0.
- Loop through each character in the string:
    * If the character is not '0', append it to res:
      res = res * 10 + (ch - '0')
- Return the final result.

Time Complexity: O(D), where D = number of digits in n
Space Complexity: O(D) due to the string conversion
*/

class Solution {
public:
    long long removeZeros(long long n) {
        long long res = 0;
        string num = to_string(n); // Convert number to string
        for(char ch: num){
            if(ch != '0'){          // Skip zeros
                res = res * 10 + (ch - '0'); // Append non-zero digit
            }
        }
        return res; // Return the final number
    }
};
