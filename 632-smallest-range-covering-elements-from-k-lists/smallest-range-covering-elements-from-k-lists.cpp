class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
         priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
            maxi=max(maxi,nums[i][0]);
        }
        int start=0;
        int end=INT_MAX;
        while(pq.size()==nums.size()){
            auto curr=pq.top();
            pq.pop();
            int mini=curr.first;
            int row=curr.second.first;
            int col=curr.second.second;
            if(maxi-mini<end-start || (maxi-mini==end-start && mini<start)){
                start=mini;
                end=maxi;
            }
            if(col+1<nums[row].size()){
                int nextelm=nums[row][col+1];
                maxi=max(maxi,nextelm);
                pq.push({nextelm,{row,col+1}});
            }
        }
        return {start,end};
    }
};