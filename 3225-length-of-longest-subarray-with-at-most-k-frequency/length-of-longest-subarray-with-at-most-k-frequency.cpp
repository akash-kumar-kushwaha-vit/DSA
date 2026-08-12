class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        unordered_map<int,int>m;
        int mxl=0;
        while(j<n){
            m[nums[j]]++;
            if(m[nums[j]]<=k){
               mxl=max(mxl,j-i+1);
            }else{
                while(m[nums[j]]>k){
                    m[nums[i]]--;
                    i++;
                }
            }
          
            j++;
        }
       
        return mxl;
    }
};