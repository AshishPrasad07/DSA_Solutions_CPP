/*
Problem: 3770. Largest Prime from Consecutive Prime Sum

You are given an integer n.

Return the largest prime number less than or equal to n that can be expressed as the sum of one or more consecutive prime numbers starting from 2. If no such number exists, return 0.

Approach:
- Generate all primes up to n using Sieve of Eratosthenes.
- Store all primes in a vector.
- Iterate through primes starting from 2, summing consecutively.
- Track the sum that is prime and <= n to get the largest valid prime.

Time Complexity:  O(n log log n + sqrt(n))  
Space Complexity: O(n)
*/

class Solution {
public:
    vector<bool> func(int n){
        vector<bool> primes(n + 1, true);
        primes[0] = false; // 0 is not prime
        primes[1] = false; // 1 is not prime
        for(int i = 2; i * i <= n; i++){
            if(primes[i] == true){
                for(int j = i * i; j <= n; j += i){
                    primes[j] = false; // mark multiples as non-prime
                }
            }
        }
        return primes;
    }

    int largestPrime(int n) {
        if(n <= 1){
            return 0;
        }
        vector<bool> primes = func(n);
        vector<int> p;
        p.reserve(50000);
        for(int i = 2; i <= n; i++){
            if(primes[i] == true){
                p.push_back(i); // store all primes
            }
        }
        long long sum = 0;
        int res = 0;
        for(int num: p){
            sum += num; // sum consecutive primes
            if(sum > n){
                break;
            }
            if(primes[sum] == true){
                res = sum; // update largest valid prime
            }
        }
        return res;
    }
};
