class Solution {
public:
    int f(int i,int j,string &s, string &t,vector<vector<long long>>&dp){
        if(j==t.size())return 1;
        if(i==s.length()) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long ans=f(i+1,j,s,t,dp);
        if(s[i]==t[j]){
            ans+=f(i+1,j+1,s,t,dp);
        }
        return dp[i][j]=ans;

    }
    int numDistinct(string s, string t) {
        vector<vector<long long>>dp(s.length(),vector<long long>(t.length(),-1));
        return f(0,0,s,t,dp);
    }
};