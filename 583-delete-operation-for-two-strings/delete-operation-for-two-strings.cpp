class Solution {
public:
    int lcs(int i,int j,string w1,string w2,vector<vector<int>>&dp){
        if(i>=w1.size() || j>=w2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(w1[i]==w2[j]){
            return dp[i][j]= 1+lcs(i+1,j+1,w1,w2,dp);
        }
        return dp[i][j]= max(lcs(i+1,j,w1,w2,dp),lcs(i,j+1,w1,w2,dp));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int len=lcs(0,0,word1,word2,dp);
        return n-len+m-len;
    }
};