class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        deque<pair<int, int>> q;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        q.push_back({0, 0});
        dist[0][0] = 0;
        while (not q.empty()) {
            auto curr = q.front();
            q.pop_front();
            int x = curr.first;
            int y = curr.second;
            int dir = grid[x][y];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int edgewt = 1;
                if (i + 1 == dir)
                    edgewt = 0;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (dist[x][y] + edgewt < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + edgewt;
                        if (edgewt == 1) {
                            q.push_back({nx, ny});
                        } else {
                            q.push_front({nx, ny});
                        }
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};