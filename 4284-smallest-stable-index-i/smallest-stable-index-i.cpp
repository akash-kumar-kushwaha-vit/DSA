class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int mx=INT_MIN;
        int minx=INT_MAX;
        int premin[n];
        int premax[n];
        for(int i=0;i<n;i++){
            if(mx<nums[i])mx=nums[i];
            premax[i]=mx;
        }
        for(int i=n-1;i>=0;i--){
            if(minx>nums[i])minx=nums[i];
            premin[i]=minx;
        }
        for(int i=0;i<n;i++){
            if(premax[i]-premin[i]<=k)return i;
        }
        return -1;
    }
};