class Solution {
public:
    int find(int x, vector<int>& par) {
        if (x == par[x])
            return x;
        return par[x] = find(par[x], par);
    }
    void Union(int a, int b, vector<int>& par, vector<int>& size) {
        a = find(a, par);
        b = find(b, par);
        if (a == b) {
            return;
        }
        if (size[a] < size[b]) {
            size[b] += size[a];
            par[a] = b;
        } else {
            size[a] += size[b];
            par[b] = a;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n);
        vector<int> size(n, 1);
        for (int i = 0; i < n; i++)
            par[i] = i;
        for (auto x : edges) {
            Union(x[0], x[1], par, size);
        }
        unordered_map<int,int>nodes;
        unordered_map<int,int>edge;
        
        for(int i=0;i<n;i++){
            nodes[find(i,par)]++;
        }
        for(auto e:edges){
            edge[find(e[0],par)]++;
        }
        int ans=0;
        for(auto &[root,ctn]:nodes){
            if(edge[root]==ctn*(ctn-1)/2)ans++;
        }

        return ans;
    }
};