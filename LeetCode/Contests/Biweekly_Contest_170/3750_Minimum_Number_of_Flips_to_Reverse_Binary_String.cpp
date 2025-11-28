/*
Problem: 3750. Minimum Number of Flips to Reverse Binary String

You are given a positive integer 'n'.

Let 's' be the binary representation of 'n' without leading zeros.

The reverse of 's' is obtained by writing its characters in the opposite order.

You may flip any bit in 's' (change 0 → 1 or 1 → 0). Each flip affects exactly one bit.

Return the minimum number of flips required to make 's' equal to its reverse.

Approach:
- Generate the binary representation of n by repeatedly taking n % 2 and dividing n by 2.
  This constructs the binary string in reverse order.
- Let s be this reversed-order binary representation.
- Compute rev = reverse(s), which corresponds to the true reversed binary string.
- Count the number of mismatched positions between s and rev.
- Each mismatch requires exactly one flip, so the answer is the mismatch count.

Time Complexity: O(log n), since binary representation length is O(log n)
Space Complexity: O(log n) for storing the binary string
*/

class Solution {
public:
    int minimumFlips(int n) {
        string s;
        while(n){
            int bit = n % 2;
            s.push_back(bit + '0');
            n = n / 2;
        }
        string rev = s;
        reverse(rev.begin(), rev.end());
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != rev[i]){
                count++;
            }
        }
        return count;
    }
};
