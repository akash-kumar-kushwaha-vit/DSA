class Solution {
public:
    pair<int, int> f(int r, int c, int pr, int pc, vector<vector<char>>& grid) {
        if (r < 0 || c < 0 || r == grid.size() || c == grid[0].size()) {
            return {pr, pc};
        }
        if (grid[r][c] == '1')
            return {pr, pc};
        if (grid[r][c] == 'L') {
            grid[r][c] = '1';
           return  f(r, c - 1, r, c, grid);
        } else if (grid[r][c] == 'R') {
            grid[r][c] = '1';
            return f(r, c + 1, r, c, grid);
        } else if (grid[r][c] == 'U') {
            grid[r][c] = '1';
          return   f(r - 1, c, r, c, grid);
        } else if (grid[r][c] == 'D') {
            grid[r][c] = '1';
         return   f(r + 1, c, r, c, grid);
        }
        return {-1,-1};
        
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {

        pair<int, int> p = f(0, 0, 0, 0, grid);
        return {p.first,p.second};
    }
};