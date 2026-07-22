class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<vector<int>>& ans,
             vector<int>& v) {
        if (node==graph.size()-1) {
            v.push_back(node);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(node);
        for (auto nebh : graph[node]) {
            dfs(nebh, graph, ans, v);
        }
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>v;
        dfs(0,graph,ans,v);
        return ans;
    }
};