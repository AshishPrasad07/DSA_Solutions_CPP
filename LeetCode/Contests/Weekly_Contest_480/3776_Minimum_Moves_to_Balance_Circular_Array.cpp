/*
Problem: 3776. Minimum Moves to Balance Circular Array

You are given a circular array 'balance' of length n, where balance[i] is the net balance of person i.

In one move, a person can transfer exactly 1 unit of balance to either their left or right neighbor.

Return the minimum number of moves required so that every person has a non-negative balance. If it is impossible, return -1.

Note: At most 1 index has a negative balance initially.

Approach:
- Calculate the total sum of balances. If sum < 0, return -1 (impossible to balance).
- Find the index of the negative balance, if any.
- If no negative balance exists, return 0 moves.
- For the negative balance, try to borrow from neighbors in increasing distance:
    - For each neighbor, take as much as needed or available, and add moves weighted by distance.
- If negative balance is fully covered, return total moves; otherwise, return -1.

Time Complexity: O(n), where n = balance.size()
Space Complexity: O(1)
*/

class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long sum = 0;
        int idx = -1, n = balance.size();
        // Compute total sum and find negative balance index
        for(int i = 0; i < n; i++){
            sum += balance[i];
            if(balance[i] < 0){
                idx = i;
            }
        }
        if(sum < 0){
            return -1;
        }
        if(idx == -1){
            return 0;
        }

        long long num = -balance[idx];
        long long res = 0;

        // Borrow from neighbors
        for(int i = 1; i < n && num > 0; i++){
            int lidx = (idx - i + n) % n;
            int ridx = (idx + i) % n;

            long long take = min((long long)balance[lidx], num);
            if(take > 0){
                balance[lidx] -= take;
                num -= take;
                res += (take * i);
            }

            if(num > 0 && lidx != ridx){
                take = min((long long)balance[ridx], num);
                if(take > 0){
                    balance[ridx] -= take;
                    num -= take;
                    res += (take * i);
                }
            }
        }

        if(num == 0){
            return res;
        }
        return -1;
    }
};
