class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int i,int j,int oi,int oj,vector<vector<char>>& grid,char oval){
        grid[i][j]=toupper(grid[i][j]);
        for(int c=0;c<4;c++){
            int nr=i+dir[c][0];
            int nc=j+dir[c][1];
            if(nr<0 || nr>=grid.size() || nc<0 || nc>=grid[0].size())continue;
             if(nr==oi && nc==oj)continue;
            if(grid[nr][nc]==toupper(oval))return true;
            if(grid[nr][nc]==oval){
                if(dfs(nr,nc,i,j,grid,oval))return true;      
            }
        }
      return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(grid[i][j]!=toupper(grid[i][j])){
                    if(dfs(i,j,-1,-1,grid,grid[i][j]))return true;
                 }
            }
        }
        return false;
    }
};