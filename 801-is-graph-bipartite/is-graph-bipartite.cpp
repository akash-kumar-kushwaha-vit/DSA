class Solution {
public:
    bool f(int n, vector<vector<int>>& graph,int i) {
        queue<int> q;
        unordered_set<int> vis;
        vector<bool> color(n, false); // red or blue
        color[i] = true;
        q.push(i);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (vis.count(node))
                continue;
            vis.insert(node);
            for (int nebh : graph[node]) {
                if (!vis.count(nebh)) {
                    q.push(nebh);
                    color[nebh] = !color[node];
                } else if (color[nebh] == color[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        for (int i = 0; i < n; i++) {
            if (!f(n,graph,i))return false;
        }
        return true;
    }
};