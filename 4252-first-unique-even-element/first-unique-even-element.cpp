class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
       unordered_map<int,int>m;
       for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
           if(m.find(nums[i])==m.end()){
              m[nums[i]]=i;
           }else{
           m[nums[i]]=200;
           }
        }
       }
       int i=INT_MAX;
       int val=0;
       for(auto x:m){
         if(x.second<i && x.second!=200){
            i=x.second;
            val=x.first;
         }
       }
       return val==0?-1:val;
    }
};