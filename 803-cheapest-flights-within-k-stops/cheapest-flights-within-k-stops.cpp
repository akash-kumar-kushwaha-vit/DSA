class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>par(n,INT_MAX);
        par[src]=0;
        for(int i=0;i<=k;i++){
            vector<int>temp=par;
            for(auto v:flights){
                if(par[v[0]]==INT_MAX)continue;
                if((par[v[0]]+v[2])<temp[v[1]]){
                    temp[v[1]]=par[v[0]]+v[2];
                }
            }
            par=temp;
        }
   
    return par[dst]==INT_MAX?-1:par[dst];
    }
};