class Solution {
public:
    void f(int i,int j,long long &sum,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())return ;
        if(grid[i][j]==0){
            return;
        }
        sum+=grid[i][j];
        grid[i][j]=0;
        f(i+1,j,sum,grid);//down
        f(i-1,j,sum,grid);//up
        f(i,j-1,sum,grid);//left;
        f(i,j+1,sum,grid);//right;

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>=1){
                    long long sum=0;
                    f(i,j,sum,grid);
                    cout<<sum<<endl;
                    if(sum%k==0)ans++;
                }
            }
        }
        return ans;
    }
};