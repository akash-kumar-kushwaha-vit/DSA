class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> grid(n, vector<int>(m, 0));

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int live = 0;

                for (int k = 0; k < 8; k++) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];

                    if (ni >= 0 && ni < n &&
                        nj >= 0 && nj < m) {

                        if (board[ni][nj] == 1) {
                            live++;
                        }
                    }
                }

                if (board[i][j] == 1) {
                    if (live == 2 || live == 3)
                        grid[i][j] = 1;
                    else
                        grid[i][j] = 0;
                }
                else {
                    if (live == 3)
                        grid[i][j] = 1;
                    else
                        grid[i][j] = 0;
                }
            }
        }

        board = grid;
    }
};