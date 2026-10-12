class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i = 0;
        int j = 0;
        int n = s.length();
        int mxl = INT_MIN;
        while (j < n) {
            if (st.count(s[j])) {
                while (s[i] != s[j]) {
                    st.erase(s[i]);
                    i++;
                }
               st.erase(s[i++]);


            }
           st.insert(s[j]);
            
            j++;
            mxl= max(mxl,(int)st.size());
        }
        return mxl==INT_MIN?n:mxl;
    }
};