/*
Problem: 3765. Complete Prime Number

You are given an integer num.

A number num is called a Complete Prime Number if every prefix and every suffix of num is prime.

Return true if num is a Complete Prime Number, otherwise return false.

Approach:
- Check each prefix of num by iterating from left to right and building the number, returning false if any prefix is not prime.
- Check each suffix of num by iterating from right to left and building the number, returning false if any suffix is not prime.
- If all prefixes and suffixes are prime, return true.

Time Complexity: tc = O(d * sqrt(n)) where d = number of digits  
Space Complexity: sc = O(d) for storing string representation
*/

class Solution {
public:
    bool isPrime(int num){
        if(num <= 1){
            return false;
        }
        for(int i = 2; i <= sqrt(num); i++){ // check divisibility up to sqrt(num)
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

    bool completePrime(int num) {
        string s = to_string(num);
        int n = 0;

        for(char ch: s){
            n = n * 10 + (ch - '0'); // build prefix
            if(!isPrime(n)){
                return false;
            }
        }

        n = 0;
        int j = 0;
        for(int i = s.size() - 1; i >= 0; i--){ 
            n = (s[i] - '0') * pow(10, j) + n; // build suffix
            if(!isPrime(n)){
                return false;
            }
            j++;
        }

        return true;
    }
};
