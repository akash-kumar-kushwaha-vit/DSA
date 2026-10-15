class Solution {
public:
    int f(int i,vector<int>& prices,bool flag,vector<vector<int>>&dp){
        if(i==prices.size())return 0;
        if(dp[i][flag]!=-1)return dp[i][flag];
        int skip=f(i+1,prices,flag,dp);
        int action;
        if(flag){
            action=-prices[i]+f(i+1,prices,false,dp);
        }else{
            action=prices[i];
            action = max(action, prices[i] + f(i + 1, prices, true,dp));
        }
        return  dp[i][flag]=max(skip,action);
   
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,prices,true,dp);
    }
};