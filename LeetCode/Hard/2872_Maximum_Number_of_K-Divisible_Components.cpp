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
    // DFS function to compute subtree sums and count k-divisible components
    int solve(vector<vector<int>>& adj, vector<int>& values, int& k, int& ans, int currNode, int p){
        long long sum = values[currNode];  // start with current node's value

        // Traverse all adjacent nodes
        for(int node : adj[currNode]){
            if(p != node){  // avoid traversing back to parent
                sum += solve(adj, values, k, ans, node, currNode);  // add subtree sums
            }
        }

        sum %= k;  // modulo k for checking divisibility

        if(sum % k == 0){  // if subtree sum divisible by k
            ans++;          // increment component count
        }

        return sum;  // return subtree sum modulo k to parent
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);  // adjacency list for the tree

        // Build adjacency list from edge list
        for(auto i : edges){
            int from = i[0];
            int to = i[1];
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        int ans = 0;  // store maximum number of k-divisible components

        solve(adj, values, k, ans, 0, -1);  // start DFS from node 0, parent = -1

        return ans;  // return final answer
    }
};
