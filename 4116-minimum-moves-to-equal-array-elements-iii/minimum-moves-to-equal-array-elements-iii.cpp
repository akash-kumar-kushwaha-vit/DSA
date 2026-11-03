class Solution {
public:
    int minMoves(vector<int>& nums) {
      
       int ans=0;
       int mx=nums[0];
       for(int x:nums){
        mx=max(mx,x);
       }
       for(int x:nums){
        if(mx==x)continue;
        ans+=(mx-x);
       }
       return ans;
       
    }
};