class Solution {
public:
    int find(int x,vector<int>&par){
        if(x==par[x])return x;
        return par[x]=find(par[x],par);
    }
    void Union(vector<int>&par,vector<int>&rank,int a,int b){
        a=find(a,par);
        b=find(b,par);
        if(a==b)return;
        if(rank[a]<rank[b]){
            rank[b]++;
            par[a]=b;
        }else{
            rank[a]++;
            par[b]=a;
        }
        
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>par(n);
        vector<int>rank(n);
        for(int i=0;i<n;i++)par[i]=i;
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    Union(par,rank,i,j);
                }
            }
         }
         int component=0;
         for(int i=0;i<n;i++){
            if(find(i,par)==i){
                component++;
            }
         }
         return n-component;
    }
};