/*
Problem: 980. Unique Paths III

You are given an m x n integer array grid where:
- 1 represents the starting square (exactly one),
- 2 represents the ending square (exactly one),
- 0 represents empty squares that can be walked over,
- -1 represents obstacles that cannot be walked over.

A valid path must:
- Start at the starting square,
- End at the ending square,
- Walk over every non-obstacle square exactly once,
- Move only in 4 directions (up, down, left, right).

Return the total number of such valid paths.

Approach:
- Count all walkable squares (including the starting square).
- Use DFS (backtracking) starting from the start cell:
    - If out of bounds or hitting an obstacle, return 0.
    - If reaching the ending square:
        - If all walkable squares have been visited, count as 1 valid path.
        - Otherwise, return 0.
    - Mark the current square as visited (-1), recursively explore all 4 directions,
      then backtrack by resetting it to 0.
- Sum all valid paths from the recursive calls and return.

Time Complexity: O(4 * M * N), where M*N is the grid size and each cell can explore 4 directions.  
Space Complexity: O(M * N)
*/

class Solution {
public:
    int nonBlocks = 0; // total number of walkable squares including start

    // DFS function to explore paths
    int func(int i, int j, int count, vector<vector<int>>& nums) {
        // If out of bounds or on an obstacle, return 0
        if(i == nums.size() || j == nums[0].size() || i < 0 || j < 0 || nums[i][j] == -1){
            return 0;
        }

        // If reaching the ending square
        if(nums[i][j] == 2){
            // Valid path only if all non-obstacle squares have been visited
            if(count == nonBlocks)
                return 1;
            return 0;
        }

        nums[i][j] = -1;  // mark current square as visited

        // Explore all 4 directions
        int up = func(i - 1, j, count + 1, nums);
        int down = func(i + 1, j, count + 1, nums);
        int left = func(i, j - 1, count + 1, nums);
        int right = func(i, j + 1, count + 1, nums);

        nums[i][j] = 0;  // backtrack to unvisited

        return up + down + left + right; // sum all valid paths
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int start1 = 0, start2 = 0;

        // Count total walkable squares and locate starting square
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 || grid[i][j] == 0){
                    if(grid[i][j] == 1){
                        start1 = i;
                        start2 = j;
                    }
                    nonBlocks++; // count walkable squares
                }
            }
        }

        // Start DFS from the starting square
        return func(start1, start2, 0, grid);
    }
};
