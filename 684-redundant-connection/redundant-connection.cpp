class Solution {
public:
     int find(int x,vector<int>&par){
        if(par[x]==x)return x;
        return par[x]=find(par[x],par);
     }
     bool Union(int a,int b,vector<int>&par,vector<int>&rank){
        a=find(a,par);
        b=find(b,par);
        if(a==b){
            return true;
        }
        if(rank[a]<rank[b]){
            rank[b]++;
            par[a]=b;
        }else{
            rank[a]++;
            par[b]=a;
        }
        return false;
     }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>par(n+1);
        vector<int>rank(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
        for(auto x:edges){
            if(Union(x[0],x[1],par,rank))return {x[0],x[1]};
        }
        return {};
    }
};