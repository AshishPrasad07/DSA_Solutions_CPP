/*
Problem: 3767. Maximize Points After Choosing K Tasks

You are given two integer arrays, technique1 and technique2, each of length n.

If the ith task is completed using technique 1, you earn technique1[i] points.
If it is completed using technique 2, you earn technique2[i] points.
You are also given an integer k, representing the minimum number of tasks that must be completed using technique 1.

You must complete at least k tasks using technique 1. The remaining tasks may be completed using either technique.

Return an integer denoting the maximum total points you can earn.

Approach:
- Compute the difference between technique1[i] and technique2[i] for each task.
- Sort tasks by descending difference.
- Select the first k tasks with largest difference to ensure at least k tasks use technique1.
- For remaining tasks, choose technique1 if difference is positive, else technique2.
- Sum points to get the maximum total.

Time Complexity:  O(n log n)  
Space Complexity: O(n)
*/

class Solution {
public:
    static bool cmp(pair<int,int>& a, pair<int,int>& b){
        return a.first > b.first; // sort descending by difference
    }

    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; i++){
            v[i] = {technique1[i] - technique2[i], i}; // difference, index
        }

        sort(v.begin(), v.end(), cmp); // sort by difference

        long long int res = 0;
        for(int i = 0; i < k; i++){
            int idx = v[i].second;
            res += (technique1[idx]); // first k tasks use technique1
        }

        for(int i = k; i < n; i++){
            int idx = v[i].second;
            if(v[i].first > 0){
                res += (technique1[idx]); // use technique1 if better
            }
            else{
                res += (technique2[idx]); // otherwise technique2
            }
        }

        return res;
    }
};
