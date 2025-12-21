/*
Problem: 3783. Mirror Distance of an Integer

You are given an integer n.

Define its mirror distance as:
abs(n - reverse(n)), where reverse(n) is the integer formed by reversing the digits of n.

Return an integer denoting the mirror distance of n.

abs(x) denotes the absolute value of x.

Approach:
- Reverse the digits of the given integer using arithmetic operations.
- Compute the absolute difference between the original number and its reversed value.
- Return the computed mirror distance.

Time Complexity:   O(d) where d = number of digits in n
Space Complexity:  O(1)
*/

class Solution {
public:
    long long func(int n){
        long long num = 0;
        while(n){
            num = num * 10 + (n % 10);
            n /= 10;
        }
        return num;
    }

    int mirrorDistance(int n) {
        long long mirror = func(n);
        return abs(n - mirror);
    }
};
