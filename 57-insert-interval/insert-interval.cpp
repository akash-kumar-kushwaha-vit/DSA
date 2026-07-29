class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        if (intervals.size() <= 0)
            return {newInterval};
        vector<vector<int>> temp;
        bool inserted = false;
        for (auto v : intervals) {
            if (!inserted && newInterval[0] <= v[0]) {
                temp.push_back(newInterval);
                inserted = true;
            }

            temp.push_back(v);
        }

        if (!inserted)
            temp.push_back(newInterval);

        vector<vector<int>> ans;
        ans.push_back(temp[0]);
        int n = temp.size();
        int k = 0;
        for (int i = 1; i < n; i++, k++) {
            if (ans[k][1] >= temp[i][0]) {
                int mine = min(ans[k][0],temp[i][0]);
                int maxe = max(temp[i][1],ans[k][1]);
                ans.pop_back();
                ans.push_back({mine, maxe});
                k--;
            } else
                ans.push_back(temp[i]);
        }
        return ans;
    }
};