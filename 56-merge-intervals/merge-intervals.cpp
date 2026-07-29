class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        vector<vector<int>> ans;
        int k ;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        if (intervals[0][1] >= intervals[1][0] && intervals[0][0]<=intervals[1][1]) {
            int mine = min(intervals[0][0], intervals[1][0]);
            int maxe = max(intervals[0][1], intervals[1][1]);
            ans.push_back({mine, maxe});
            k=0;
        }else{
            ans.push_back(intervals[0]);
            ans.push_back(intervals[1]);
            k=1;
        }
        
        for (int i = 2; i < n; i++,k++) {
            if (ans[k][1] >= intervals[i][0] && ans[k][0]<=intervals[i][1]) {
                int mine = min(ans[k][0], intervals[i][0]);
                int maxe = max(ans[k][1], intervals[i][1]);
                ans.pop_back();
                ans.push_back({mine, maxe});
                k--;
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};