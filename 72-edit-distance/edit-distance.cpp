class Solution {
public:
    vector<vector<int>> dp;

    int f(int i, int j, string &w1, string &w2) {
        // If word1 is finished
        if (i == w1.size()) {
            return w2.size() - j;
        }

        // If word2 is finished
        if (j == w2.size()) {
            return w1.size() - i;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters are already same
        if (w1[i] == w2[j]) {
            return dp[i][j] = f(i + 1, j + 1, w1, w2);
        }

        // Replace
        int replace = 1 + f(i + 1, j + 1, w1, w2);

        // Delete
        int del = 1 + f(i + 1, j, w1, w2);

        // Insert
        int insert = 1 + f(i, j + 1, w1, w2);

        return dp[i][j] = min({replace, del, insert});
    }

    int minDistance(string word1, string word2) {
        dp.assign(word1.size(), vector<int>(word2.size(), -1));

        return f(0, 0, word1, word2);
    }
};