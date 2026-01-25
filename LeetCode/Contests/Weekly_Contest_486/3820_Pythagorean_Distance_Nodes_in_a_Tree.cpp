/*
Problem: 3820. Pythagorean Distance Nodes in a Tree

You are given an undirected tree with n nodes numbered from 0 to n - 1 and three distinct 
target nodes x, y, and z. A node u is called special if the distances from u to x, y, and z 
form a Pythagorean triplet. Return the number of special nodes.

Approach:
- Build the adjacency list of the tree.
- Run BFS from nodes x, y, and z to compute distances to all nodes.
- For each node, sort the three distances and check if they form a Pythagorean triplet: a^2 + b^2 = c^2.
- Count nodes satisfying the condition.

Time Complexity:   O(n)
Space Complexity:  O(n)
*/

class Solution {
public:
    vector<int> bfs(int s, int n, vector<vector<int>>& adj){
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: adj[u]){
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> disX = bfs(x, n, adj);
        vector<int> disY = bfs(y, n, adj);
        vector<int> disZ = bfs(z, n, adj);
        int res = 0;
        for(int i = 0; i < n; i++){
            vector<int> dis(3);
            dis[0] = disX[i];
            dis[1] = disY[i];
            dis[2] = disZ[i];
            sort(dis.begin(), dis.end());
            if(1LL * dis[0] * dis[0] + 1LL * dis[1] * dis[1] == 1LL * dis[2] * dis[2]){
                res++;
            }
        }
        return res;
    }
};
