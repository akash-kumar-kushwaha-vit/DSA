class Solution {
public:

    int n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int r1, int c1, int r2) {

        int c2 = r1 + c1 - r2;

        // Out of bounds
        if (r1 >= n || c1 >= n ||
            r2 >= n || c2 >= n) {
            return -1e9;
        }

        // Thorn
        if (grid[r1][c1] == -1 ||
            grid[r2][c2] == -1) {
            return -1e9;
        }

        // Reached destination
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        if (dp[r1][c1][r2] != -1) {
            return dp[r1][c1][r2];
        }

        int cherries = 0;

        // Person 1
        cherries += grid[r1][c1];

        // Person 2 (don't count twice if same cell)
        if (r1 != r2 || c1 != c2) {
            cherries += grid[r2][c2];
        }

        // Four possibilities
        int a = solve(grid, r1 + 1, c1, r2 + 1);
        int b = solve(grid, r1 + 1, c1, r2);
        int c = solve(grid, r1, c1 + 1, r2 + 1);
        int d = solve(grid, r1, c1 + 1, r2);

        cherries += max({a, b, c, d});

        return dp[r1][c1][r2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        n = grid.size();

        dp.assign(
            n,
            vector<vector<int>>(
                n,
                vector<int>(n, -1)
            )
        );

        int ans = solve(grid, 0, 0, 0);

        return max(0, ans);
    }
};