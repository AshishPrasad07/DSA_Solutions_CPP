/*
Problem: 3710. Maximum Partition Factor

You are given a 2D array of points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

The Manhattan distance between two points points[i] = [xi, yi] and points[j] = [xj, yj] is |xi - xj| + |yi - yj|.

Split the n points into exactly two non-empty groups. The partition factor of a split is the minimum Manhattan distance among all unordered pairs of points that lie in the same group.

Return the maximum possible partition factor over all valid splits.

Approach:
1. If there are only 2 points, return 0 as no intra-group pairs exist.
2. For all pairs of points, calculate their Manhattan distances and track the maximum distance.
3. Perform binary search on possible partition factors from 0 to the maximum Manhattan distance.
4. For each candidate factor (mid-point in binary search), build a graph where edges represent points that are too close (i.e., their Manhattan distance is less than the current factor).
5. Check if the graph is bipartite using BFS. If the graph is bipartite, update the answer and continue with the binary search.

Time Complexity: O(n^2 * log(maxDist)) where n is the number of points and maxDist is the maximum Manhattan distance between any two points.
Space Complexity: O(n^2) for the graph and additional storage.
*/

class Solution {
public:
    typedef pair<int, int> P;

    bool func(const vector<vector<int>>& graph, int n) {
        vector<int> color(n, -1);  // -1: uncolored, 0: group 1, 1: group 2
        for (int i = 0; i < n; i++) {
            if (color[i] != -1) {
                continue;
            }
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[u] == color[v]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 2) {
            return 0;  // No intra-group pairs exist when there are exactly two points
        }

        vector<P> pt(n);
        for (int i = 0; i < n; i++) {
            pt[i] = {points[i][0], points[i][1]};  // Store coordinates in pair (xi, yi)
        }

        long long maxDist = 0;
        // Calculate the maximum Manhattan distance between any two points
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxDist = max(maxDist, abs(pt[i].first - pt[j].first) + abs(pt[i].second - pt[j].second));
            }
        }

        long long left = 0, right = maxDist, ans = 0;

        // Binary search on the partition factor
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            vector<vector<int>> graph(n);

            // Build the graph: add an edge between points whose Manhattan distance is less than mid
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (abs(pt[i].first - pt[j].first) + abs(pt[i].second - pt[j].second) < mid) {
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
                }
            }

            // Check if the graph can be bipartite (i.e., if we can split the points into two groups)
            if (func(graph, n)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;  // Return the maximum partition factor found
    }
};
