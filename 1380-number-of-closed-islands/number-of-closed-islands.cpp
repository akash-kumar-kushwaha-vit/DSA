class Solution {
public:
    bool isSrounded(int i,int j,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())return false;
        if(grid[i][j]==1 || grid[i][j]==-1)return true;
        grid[i][j]=-1;
       bool l= isSrounded(i,j-1,grid);
       bool r= isSrounded(i,j+1,grid);
     bool u=   isSrounded(i-1,j,grid);
    bool d=    isSrounded(i+1,j,grid);
    return l && r && u && d;

    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=1 && grid[i][j]!=-1){
                    if(isSrounded(i,j,grid))ans++;
                }
            }
        }
        return ans;
    }
};