/*
Problem: 3754. Concatenate Non-Zero Digits and Multiply by Sum I

You are given an integer 'n'.

Form a new integer x by concatenating all the non-zero digits of n in their original order. 
If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.

Approach:
- Convert n to string to process each digit.
- Iterate through the digits:
    - If the digit is non-zero, add it to the concatenated number and update sum.
- Multiply the resulting number x with its sum of digits.
- Return the result.

Time Complexity: O(D), where D = number of digits in n
Space Complexity: O(D)
*/

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long res = 0;                // Concatenated number from non-zero digits
        string s = to_string(n);          // Convert n to string for digit-wise processing
        int sum = 0;                      // Sum of non-zero digits

        for(char ch: s){
            if(ch != '0'){                // Consider only non-zero digits
                sum += (ch - '0');        // Add to sum
                res = res * 10 + (ch - '0'); // Concatenate to form new number
            }
        }

        return res * sum;                 // Multiply x with its digit sum
    }
};
