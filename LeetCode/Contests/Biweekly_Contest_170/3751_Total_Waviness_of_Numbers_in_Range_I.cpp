/*
Problem: 3751. Total Waviness of Numbers in Range I

You are given two integers 'num1' and 'num2' representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:
- A digit is a peak if it is strictly greater than both of its immediate neighbors.
- A digit is a valley if it is strictly less than both of its immediate neighbors.
- The first and last digits cannot be peaks or valleys.
- Any number with fewer than 3 digits has waviness = 0.

Return the total sum of waviness for all numbers in the range [num1, num2].

Approach:
- Iterate through every number from num1 to num2.
- Convert each number to a string to easily inspect digit neighbors.
- For each digit at index j (1 ≤ j ≤ len-2):
    - Check if it's a peak: s[j] > s[j-1] && s[j] > s[j+1]
    - Check if it's a valley: s[j] < s[j-1] && s[j] < s[j+1]
- Count such positions for each number and add to the global total.

Time Complexity: O((num2 - num1 + 1) * log n)
Space Complexity: O(log n)
*/

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for(int i = num1; i <= num2; i++){
            string s = to_string(i);
            for(int j = 1; j < s.size() - 1; j++){
                if((s[j] - '0') > (s[j - 1] - '0') && (s[j] - '0') > (s[j + 1] - '0')){
                    count++;
                }
                else if((s[j] - '0') < (s[j - 1] - '0') && (s[j] - '0') < (s[j + 1] - '0')){
                    count++;
                }
            }
        }
        return count;
    }
};
