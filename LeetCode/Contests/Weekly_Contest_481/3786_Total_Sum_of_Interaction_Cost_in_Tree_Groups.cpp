/*
Problem: 3786. Total Sum of Interaction Cost in Tree Groups

You are given an integer n and an undirected tree with n nodes numbered from 0 to n - 1. 
This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi] indicates an undirected edge between nodes ui and vi.

You are also given an integer array group of length n, where group[i] denotes the group label assigned to node i.

Two nodes u and v are considered part of the same group if group[u] == group[v].
The interaction cost between u and v is defined as the number of edges on the unique path connecting them in the tree.
Return an integer denoting the sum of interaction costs over all unordered pairs (u, v) with u != v such that group[u] == group[v].

Approach:
- Build the tree using adjacency lists from the edges array.
- Group nodes based on their group labels using a map.
- For each group with at least two nodes:
  - Perform a DFS to count the number of nodes in the current group in the subtree of each node.
  - For each edge, compute the interaction cost contribution:
    - Let num be the number of nodes in the current group in one part of the edge's cut.
    - Contribution = num * (total nodes in group - num).
  - Sum contributions over all edges.
- Return the total sum of interaction costs.

Time Complexity:   O(n)
Space Complexity:  O(n)
*/

class Solution {
public:
    vector<vector<int>> tree;
    vector<int> grp;
    vector<int> grpCount;

    int dfs(int u, int p, int g){
        grpCount[u] = (grp[u] == g ? 1 : 0);
        for(int v : tree[u]){
            if(v == p) continue;
            grpCount[u] += dfs(v, u, g);
        }
        return grpCount[u];
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        tree.assign(n, vector<int>());
        grp = group;

        for(auto e : edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        unordered_map<int, vector<int>> groups;
        for(int i = 0; i < n; i++){
            groups[group[i]].push_back(i);
        }

        long long res = 0;
        grpCount.assign(n, 0);

        for(auto p : groups){
            int g = p.first;
            int totalGroup = p.second.size();
            if(totalGroup < 2) continue;

            dfs(p.second[0], -1, g);

            for(auto e : edges){
                long long num = grpCount[e[0]];
                if(num > grpCount[e[1]]) num = grpCount[e[1]];
                res += num * (totalGroup - num);
            }
        }

        return res;
    }
};
