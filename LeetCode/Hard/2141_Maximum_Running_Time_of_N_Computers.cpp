/*
Problem: 2141. Maximum Running Time of N Computers

You have n computers and an integer array batteries where batteries[i] represents 
the minutes the i-th battery can run a computer.

You want to run all n computers simultaneously for the maximum number of minutes.
You may swap batteries at any integer time moment with zero cost.
Batteries cannot be recharged.

Goal:
Return the maximum number of minutes you can run all the n computers simultaneously.

Approach:
- Use binary search on the answer.
- Define a helper function isPossible(mid):
    - Total energy required = n * mid.
    - Each battery contributes min(battery[i], mid).
    - If total contribution ≥ required → mid is achievable.
- Lower bound = minimum battery value.
- Upper bound = (sum of all batteries) / n.
- Binary search to find maximum feasible mid.

Time Complexity: O(n log M)  
Space Complexity: O(1)
*/

class Solution {
public:
    // Check if we can run all n computers for 'mid' minutes
    bool isPossible(long long mid, vector<int>& battery, int n){
        long long total = n * mid;     // total energy required

        for(int num: battery){
            // Contribute either full battery or only 'mid' (whichever is smaller)
            if(num < mid){
                total -= num;
            }
            else{
                total -= mid;
            }

            // If requirement is met early, return true
            if(total <= 0){
                return true;
            }
        }

        return false;   // not enough total energy
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long s = INT_MAX, e = 1e15;   // s = low bound, e = large placeholder high bound

        // Calculate actual upper bound and smallest battery
        for(int num: batteries){
            e += num;           // accumulate total battery power
            if(s > num){
                s = num;        // track smallest battery (lower bound)
            }
        }

        e /= n;                 // maximum equally distributed runtime

        // If number of batteries equals n, answer is simply smallest battery
        if(batteries.size() == n){
            return s;
        }

        long long ans = s;                      // best found answer
        long long mid = s + (e - s) / 2;        // initial mid

        // Binary search for maximum feasible runtime
        while(s <= e){
            if(isPossible(mid, batteries, n)){
                ans = mid;         // mid is valid → try for more
                s = mid + 1;
            }
            else{
                e = mid - 1;       // mid too large → reduce
            }

            mid = s + (e - s) / 2; // update mid
        }

        return ans;   // return best possible runtime
    }
};
