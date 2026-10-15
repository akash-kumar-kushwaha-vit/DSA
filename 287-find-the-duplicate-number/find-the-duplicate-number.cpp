class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i){

          if(nums[nums[i]]==nums[i])return nums[i];
             else{
                swap(nums[i],nums[nums[i]]);
             }
        }
        return nums[0];
    }
};