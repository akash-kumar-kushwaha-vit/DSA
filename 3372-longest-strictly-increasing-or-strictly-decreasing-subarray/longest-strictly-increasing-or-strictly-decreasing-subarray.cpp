class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int j=1;
        int inc=1;
        int dec=1;
        int ans=1;
        while(j<nums.size()){
          if(nums[j]>nums[j-1]){
               inc++;
               dec=1;

            }else if(nums[j]<nums[j-1]){
                dec++;
                inc=1;
                
            }else{
                dec=1;
                inc=1;
            }
        ans=max({ans,inc,dec});
            j++;
        }
        return ans;
        
    }
};