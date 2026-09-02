class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto x:m){
            auto v=x.second;
            int idx=v[0];
            bool flag=true;
            for(int i:v){
                if(idx!=i){
                    flag=false;
                    break;
                }
                idx++;            
            }
            if(flag)ans++;
            
        }
        return ans;
    }
};