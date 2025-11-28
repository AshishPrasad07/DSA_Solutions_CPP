/*
Problem: 3753. Total Waviness of Numbers in Range II

You are given two integers 'num1' and 'num2' representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:
- A digit is a peak if it is strictly greater than both of its immediate neighbors.
- A digit is a valley if it is strictly less than both of its immediate neighbors.
- The first and last digits cannot be peaks or valleys.
- Any number with fewer than 3 digits has waviness = 0.

Return the total sum of waviness for all numbers in the range [num1, num2].

Approach:
- Use digit DP to count the total waviness efficiently over large ranges.
- Maintain the previous two digits (p2, p1) to check for peaks and valleys.
- DFS with memoization:
    - pos: current digit position
    - tight: whether current prefix matches the upper bound
    - started: whether non-leading-zero digits have started
    - p2, p1: previous two digits
- At each position, iterate over allowed digits, update peak/valley count accordingly.
- Compute total waviness for range [0, num2] and subtract waviness for [0, num1-1].

Time Complexity: O(20 * 2 * 2 * 11 * 11 * 10) ≈ O(48400) (constant)
Space Complexity: O(20 * 2 * 2 * 11 * 11) for DP and visited arrays
*/

class Solution {
public:
    string s;
    long long waysDp[20][2][2][11][11];   // DP for number of ways
    long long wavDp[20][2][2][11][11];    // DP for total waviness
    bool vis[20][2][2][11][11];           // visited array for memoization

    // DFS function for digit DP
    pair<long long, long long> dfs(int pos, int tight, int started, int p2, int p1){
        if(pos == s.size()){
            return {1, 0};   // 1 way, 0 waviness
        }

        if(vis[pos][tight][started][p2][p1]){
            return {waysDp[pos][tight][started][p2][p1], wavDp[pos][tight][started][p2][p1]};
        }

        long long &ways = waysDp[pos][tight][started][p2][p1];
        long long &wav = wavDp[pos][tight][started][p2][p1];
        vis[pos][tight][started][p2][p1] = true;
        ways = 0;
        wav = 0;

        int limit = tight ? s[pos] - '0' : 9;  // Maximum digit allowed at this position

        for(int d = 0; d <= limit; d++){
            int nt = tight && (d == limit);  // new tight constraint

            if(!started){
                if(d == 0){
                    auto nxt = dfs(pos + 1, nt, 0, 10, 10);  // still leading zeros
                    ways += nxt.first;
                    wav += nxt.second;
                } else {
                    auto nxt = dfs(pos + 1, nt, 1, 10, d);   // first non-zero digit
                    ways += nxt.first;
                    wav += nxt.second;
                }
            } else {
                int add = 0;
                if(p2 != 10){  // Check peak/valley only if at least 3 digits
                    if(p1 > p2 && p1 > d) add = 1;       // peak
                    else if(p1 < p2 && p1 < d) add = 1;  // valley
                }
                auto nxt = dfs(pos + 1, nt, 1, p1, d);
                ways += nxt.first;
                wav += nxt.second + add * nxt.first;     // add peak/valley contribution
            }
        }

        return {ways, wav};
    }

    // Compute total waviness from 0 to n
    long long waveSum(long long n){
        if(n < 0) return 0;
        s = to_string(n);
        memset(vis, 0, sizeof(vis));
        auto ans = dfs(0, 1, 0, 10, 10);
        return ans.second;
    }

    // Total waviness in range [num1, num2]
    long long totalWaviness(long long num1, long long num2){
        return waveSum(num2) - waveSum(num1 - 1);
    }
};
