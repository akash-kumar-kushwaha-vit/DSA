class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
        unordered_set<char>st;
        int i=0;
        int j=0;
        int n=s.length();
        if(n<=0)return 0;
        int ans=INT_MIN;
        while(j<n){
           
            if(st.count(s[j])){
                while(s[i]!=s[j]){
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i++]);
            }
             ans=max(ans,j-i+1);
             
            st.insert(s[j++]);
        }
        return ans==INT_MIN?1:ans;

    }
};