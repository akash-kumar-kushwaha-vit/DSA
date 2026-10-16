class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int>m;
        int t=0;
        for(int i=0;i<nums.size();i++){
            if(x==nums[i]){
                m[++t]=i;
            }
        }
        vector<int>ans;
        for(int q:queries){
            if(m.find(q)!=m.end()){
                ans.push_back(m[q]);
            }else ans.push_back(-1);
        }
        return ans;
    }
};