class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
         vector<vector<int>>ans;
         int n1=nums1.size();
         int n2=nums2.size();
         for(int i=0;i<min(n1,k);i++){
           pq.push({nums1[i]+nums2[0],{i,0}});
         }
         while(k-- && !pq.empty()){
            auto curr=pq.top().second;
            pq.pop();
            int i=curr.first;
            int j=curr.second;
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<n2){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
         }

       
       return ans;
    }
};