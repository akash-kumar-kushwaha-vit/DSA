class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> mx;
        unordered_map<int,int>m;
        for(int x:nums ){
            m[x]++;
        }
        for(auto x:m){
            mx.push({x.second,x.first});
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(mx.top().second);
            mx.pop();
        }

     return ans;   
    }
};