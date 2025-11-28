/*
Problem: 3752. Lexicographically Smallest Negated Permutation that Sums to Target

You are given a positive integer 'n' and an integer 'target'.

Return the lexicographically smallest array of integers of size n such that:
- The sum of its elements equals target.
- The absolute values of its elements form a permutation of size n.
- If no such array exists, return an empty array.

A permutation of size n is a rearrangement of integers 1, 2, ..., n.

Approach:
- Compute the maximum possible sum S = n(n+1)/2.
- Flipping a value x from +x to -x reduces the total sum by 2x.
- To reach target, the required reduction is del = S - target.
- Greedily flip the largest values first (from n downwards) as long as 2*x ≤ del.
- Collect all flipped values (negatives), sort them, and put them in front to ensure
  the final array is lexicographically smallest.
- Append remaining positive values afterward.

Time Complexity: O(n log n) due to sorting negative values
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {

        long long num = (long long)n * (n + 1) / 2;   // Maximum possible sum

        // If target is outside the achievable range, return empty array
        if(target > num || target < -num){
            return {};
        }

        vector<int> res(n);
        for(int i = 0; i < n; i++){
            res[i] = i + 1;   // Initial permutation: [1, 2, ..., n]
        }

        vector<int> neg;       // Stores flipped negative values
        long long del = num - target;   // Required reduction to reach target

        // Greedily flip largest numbers first
        for(int i = n - 1; i >= 0 && del > 0; i--){
            int val = res[i];
            long long temp = 2LL * val;  // Flipping +val to -val reduces sum by 2*val

            if(temp <= del){
                res[i] = -val;           // Flip the value
                del -= temp;             // Update remaining reduction needed
                neg.push_back(-val);     // Store flipped value
            }
        }

        // If we couldn't reach target exactly, no valid permutation
        if(del != 0){
            return {};
        }

        sort(neg.begin(), neg.end());   // Sort negatives for lexicographically smallest result

        vector<int> ans;

        // Add all negative numbers first
        ans.insert(ans.end(), neg.begin(), neg.end());

        // Add remaining positive numbers
        for(int x: res){
            if(x > 0){
                ans.push_back(x);
            }
        }

        return ans;
    }
};
