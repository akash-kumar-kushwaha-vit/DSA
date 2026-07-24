class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        if(q.empty() || q.size()==n*n)return -1;
        int ans = -1;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            int size = q.size();
            ans++;
            while (size--) {
                auto [i, j] = q.front();
                q.pop();

                for (int c = 0; c < 4; c++) {
                    int nr = i + dir[c][0];
                    int nc = j + dir[c][1];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                        continue;
                    if (grid[nr][nc] == 0) {
                        grid[nr][nc] = 1; // visited
                        q.push({nr, nc});
                    }
                }
            }
        }
        return ans;
    }
};