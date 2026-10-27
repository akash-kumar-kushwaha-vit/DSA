class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, ".");
        string s = "";
        for (int i = 1; i < n; i++) {
            s += "#";
        }
        for (int i = 0; i < m - 1; i++) {
            ans[i] += s;
        }
        for (int i = 1; i < n; i++) {
            ans[m - 1] += ".";
        }
        return ans;
    }
};