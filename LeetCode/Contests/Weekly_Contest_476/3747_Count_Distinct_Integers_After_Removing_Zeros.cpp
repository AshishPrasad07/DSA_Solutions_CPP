/*
Problem: 3747. Count Distinct Integers After Removing Zeros

You are given a positive integer 'n'.

For every integer x from 1 to n, we write down the integer obtained by removing all 
zeros from the decimal representation of x.

Return an integer denoting the number of distinct integers written down.

Approach:
- Removing zeros from numbers creates many duplicates, so we need to count how many
  *distinct* results are possible from all numbers in the range [1, n].
- Instead of enumerating all numbers (which is impossible for large n), we use 
  digit DP to generate all possible non-zero digit sequences formed by removing zeros.
- State definition:
    pos → current digit position
    t   → tight constraint (whether the prefix is equal to n's prefix)
    st  → started flag (whether we have chosen a non-zero digit so far)
- Transitions:
    - If st == 0 (we haven't started):
        - Choosing digit 0 → still not started
        - Choosing digit 1–9 → start and continue
    - If st == 1 (we have started):
        - We cannot add zero anymore (zeros are removed), so skip 0
        - Add digits 1–9 as next digits
- At the end (pos == length):
    - Count only sequences where st == 1 (valid numbers)
- This DP effectively counts all distinct non-zero digit sequences ≤ the zero-removed 
  representation of n.

Time Complexity: O(20 * 2 * 2 * 10) = O(1) per DP, very fast
Space Complexity: O(1) additional (DP array is constant size)
*/

class Solution {
public:
    string s;
    long long dp[20][2][2];
    bool vis[20][2][2];

    long long dfs(int pos, int t, int st){
        if(pos == s.size()){
            return st ? 1 : 0;
        }
        if(vis[pos][t][st]){
            return dp[pos][t][st];
        }
        vis[pos][t][st] = true;

        long long ans = 0;
        int limit = t ? (s[pos] - '0') : 9;

        for(int d = 0; d <= limit; d++){
            int nt = (t && d == limit);

            if(!st){
                // haven't started yet
                if(d == 0){
                    ans += dfs(pos + 1, nt, 0);
                } else {
                    ans += dfs(pos + 1, nt, 1);
                }
            } else {
                // already started, cannot choose 0
                if(d == 0) continue;
                ans += dfs(pos + 1, nt, 1);
            }
        }

        return dp[pos][t][st] = ans;
    }

    long long countDistinct(long long n) {
        s = to_string(n);
        memset(vis, 0, sizeof(vis));
        return dfs(0, 1, 0);
    }
};
