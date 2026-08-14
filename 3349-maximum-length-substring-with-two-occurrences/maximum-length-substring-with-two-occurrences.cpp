class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> f(26, 0);
        int i = 0;
        int j = 0;
        int n = s.length();
        int mxl = INT_MIN;
        while (j < n) {
            f[s[j] - 'a']++;
            while (f[s[j] - 'a'] > 2) {
                f[s[i++] - 'a']--;
            }
           mxl = max(mxl, j - i + 1);

            j++;
        }
        return mxl;
    }
};