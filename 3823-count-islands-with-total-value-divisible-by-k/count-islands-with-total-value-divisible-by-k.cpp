class Solution {
public:
    void f(int i,int j,vector<vector<int>>& grid,long long &sum){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())return ;
        if(grid[i][j]==0 || grid[i][j]==-1)return;
        sum+=grid[i][j];
        grid[i][j]=-1;
        f(i,j-1,grid,sum);
        f(i,j+1,grid,sum);
        f(i+1,j,grid,sum);
        f(i-1,j,grid,sum);
        
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0 && grid[i][j]!=-1){
                    long long sum=0;
                    f(i,j,grid,sum);
                    if(sum%k==0)ans++;
                }
                
            }
        }
        return ans;
    }
};