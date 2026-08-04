class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {

        int n = matrix.size();
        int m = matrix[0].size();

        if (j < 0 || j >= m)
            return 1e9;     // instead of INT_MAX

        if (i == n)
            return 0;

        if (dp[i][j] !=1000)
            return dp[i][j];

        int left = f(i + 1, j - 1, matrix, dp);
        int down = f(i + 1, j, matrix, dp);
        int right = f(i + 1, j + 1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min({left, down, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 1000));

        int ans = 1e9;

        for (int j = 0; j < m; j++)
            ans = min(ans, f(0, j, matrix, dp));

        return ans;
    }
};