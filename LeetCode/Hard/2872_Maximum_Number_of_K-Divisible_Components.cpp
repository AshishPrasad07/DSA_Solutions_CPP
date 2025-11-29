/*
Problem: 2872. Maximum Number of K-Divisible Components

You are given an undirected tree with n nodes labeled from 0 to n - 1.  
Each node has a value, and you are also given an integer k.

A valid split is formed by removing any number of edges such that each resulting connected
component has a total value divisible by k.

Goal:
Return the maximum number of such k-divisible components obtainable from the tree.

Approach:
- Build adjacency list for the tree.
- Use DFS to compute the sum of each subtree.
- For each subtree:
    - Add child subtree sums to current node's value.
    - Take modulo k.
    - If the subtree sum % k == 0, it forms a valid component → increment ans.
- Continue DFS until entire tree is processed.

Time Complexity: O(n)  
Space Complexity: O(n) (Adjacency list + recursion stack)
*/

class Solution {
    int solve(vector<vector<int>>& adj, vector<int>& values, int& k, int& ans, int currNode, int p){
        long long sum = values[currNode];
        for(int node : adj[currNode]){
            if(p != node){
                sum += solve(adj, values, k, ans, node, currNode);
            }
        }
        sum %= k;
        if(sum % k == 0){
            ans++;
        }
        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto i : edges){
            int from = i[0];
            int to = i[1];
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        int ans = 0;
        solve(adj, values, k, ans, 0, -1);
        return ans;
    }
};
