class Solution {
public:
    int f(int i,int k,int curr,string &s,vector<vector<int>>&dp){
        if(i==s.length()){
            return 0;
        }
        int c=curr+1;
        if(dp[i][c]!=-1)return dp[i][c];
        int skip=f(i+1,k,curr,s,dp);
        int next=0;
        if( curr==-1 || abs(curr-(s[i]-'a'))<=k){
            next=1+f(i+1,k,s[i]-'a',s,dp);
        }
        return dp[i][c]=max(skip,next);
    }
    int longestIdealString(string s, int k) {
    
        vector<vector<int>>dp(s.length(),vector<int>(27,-1));
        return f(0,k,-1,s,dp);
    }
};