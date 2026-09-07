class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<int> dp;

    int solve(int i, string &s) {
        if (i == s.size()) return 1;      

        if (dp[i] != -1) return dp[i];

        long long ans = 1;                
        vector<int> used(26, 0);

        for (int j = i; j < s.size(); j++) {
            int c = s[j] - 'a';
            if (used[c]) continue;       
            used[c] = 1;

            ans = (ans + solve(j + 1, s)) % MOD;
        }

        return dp[i] = ans;
    }

    int distinctSubseqII(string s) {
        dp.assign(s.size(), -1);

        return (solve(0, s) - 1 + MOD) % MOD;
    }
};