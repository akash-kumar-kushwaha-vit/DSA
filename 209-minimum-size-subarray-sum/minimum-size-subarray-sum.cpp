class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sum=0;
        int ml=INT_MAX;
        while(j<nums.size()){
           sum+=nums[j];
           j++;
           while(sum>=target){
             ml=min(ml,j-i);
             sum-=nums[i];
             i++;
           }
        }
        if(ml==INT_MAX)return 0;
        return ml;
    }
};