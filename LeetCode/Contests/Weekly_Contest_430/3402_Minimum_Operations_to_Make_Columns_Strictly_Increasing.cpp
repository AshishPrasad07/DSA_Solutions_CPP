/*
Problem: 3402. Minimum Operations to Make Columns Strictly Increasing

You are given a m x n matrix grid consisting of non-negative integers.
In one operation, you can increment the value of any grid[i][j] by 1.
Return the minimum number of operations needed to make all columns of grid strictly increasing.

Approach:
- Iterate through each column of the grid.
- For each column, compare adjacent rows to check if grid[i][j] is less than or equal to grid[i-1][j].
- If it is, increment grid[i][j] so that it becomes strictly greater than grid[i-1][j].
- Keep track of the total number of operations needed for this update.

Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
Space Complexity: O(1), as we modify the grid in place and use constant space.
*/

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        // Edge case: if there is only one row, no operations are needed
        if (grid.size() == 1) {
            return 0;
        }

        int ans = 0;  // To track the total number of operations

        // Iterate over all columns
        for (int j = 0; j < grid[0].size(); j++) {
            // Iterate over rows, starting from the second row
            for (int i = 1; i < grid.size(); i++) {
                // If current value is not strictly greater than the previous value in the column
                if (grid[i][j] <= grid[i - 1][j]) {
                    // Calculate the number of operations to make grid[i][j] strictly greater than grid[i-1][j]
                    ans += (grid[i - 1][j] - grid[i][j] + 1);
                    // Update grid[i][j] to be strictly greater than grid[i-1][j]
                    grid[i][j] = grid[i - 1][j] + 1;
                }
            }
        }

        return ans;  // Return the total number of operations
    }
};
