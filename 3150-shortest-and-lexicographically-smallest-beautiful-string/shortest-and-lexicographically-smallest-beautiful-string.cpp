class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.length();
        int len = INT_MAX;
        string ans = "";
        while (j < n) {
            if (s[j] == '1') {
                k--;
            }
            if (k == 0) {
                while (k <= 0) {
                    if (s[i] == '1') {
                        k++;
                    }
                    i++;
                }
                if (len > j - i + 2) {
                    ans = s.substr(i - 1, j - i + 2);
                    len = j - i + 2;
                } else if (len == j - i + 2) {
                    string t = s.substr(i - 1, j - i + 2);
                    if(ans>t){
                        ans=t;
                    }
                   
                }
            }
            j++;
        }
        return ans;
    }
};