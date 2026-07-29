class Solution {
public:
    bool f(vector<int>& nums,int i,int n,vector<int>&dp){
        if(i>=n-1)return true;
        if(dp[i]!=-1)return dp[i];
        for(int c=1;c<=nums[i];c++){
            if(f(nums,i+c,n,dp))return dp[i]=1;
        }
        return dp[i]=0;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return f(nums,0,nums.size(),dp);
    }
};