class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>v(101,-1);
        int mine=INT_MAX;
        int maxe=INT_MIN;
        for(int x:nums){
            v[x]=x;
            mine=min(mine,x);
            maxe=max(maxe,x);
        }
        vector<int>ans;
        for(int i=mine;i<=maxe;i++){
            if(v[i]==-1)ans.push_back(i);
        }
        return ans;
    }
};