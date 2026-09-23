class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int target=0;
       for(int num:nums)target+=num;
       target-=x;
       int i=0;
       int j=0;
       int sum=0;
       int maxw=INT_MIN;
       if( target<0)return -1;
       while(j<nums.size()){
        sum+=nums[j++];
        while(sum>target){
            sum-=nums[i++];
        }
        if(sum==target)maxw=max(maxw,j-i);
       }
       return maxw==INT_MIN?-1: nums.size()-maxw;
    }
};