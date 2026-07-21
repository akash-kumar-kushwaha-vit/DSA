class Solution {
public:
    int find(int x,vector<int>&par){
        if(x==par[x])return x;
        return par[x]=find(par[x],par);
    }
    void Union(int a,int b,vector<int>&par,vector<int>&size){
        a=find(a,par);
        b=find(b,par);
        if(a==b)return;
        if(size[a]>size[b]){
            size[a]+=size[b];
            par[b]=a;
        }else{
            size[b]+=size[a];
            par[a]=b;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>par(n);
        vector<int>size(n,1);
        for(int i=0;i<n;i++)par[i]=i;
        for(auto x:edges){
            Union(x[0],x[1],par,size);
        }
        long long ans=0;
        long long rem=n;
        unordered_set<int>set;//par
        for(int i=0;i<n;i++){
            int x=find(i,par);
           set.insert(x);
        }
        for(int x:set){
            rem-=size[x];
            ans+=rem*size[x];
        }
       
        return ans;

    }
};