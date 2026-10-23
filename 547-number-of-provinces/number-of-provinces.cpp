class Solution {
public:
    
    void f(int node,vector<vector<int>>& isConnected,vector<int>&vis){
         vis[node]=1;
         for(int j=0;j<isConnected.size();j++){
            if(!vis[j] && isConnected[node][j]){
                f(j,isConnected,vis);
            }
         }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                f(i,isConnected,vis);
            }
        }
        return ans;
    }
};