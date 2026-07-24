class Solution {
public:
   int find(vector<int>&parent,int x){
    if(parent[x]==x)return parent[x];
    return parent[x]=find(parent,parent[x]);
   }
   void Union(vector<int>&parent,vector<int>&rank,int a,int b){
    a=find(parent,a);
    b=find(parent,b);
    if(a==b)return;
    if(rank[a]>rank[b]){
        rank[a]++;
        parent[b]=a;
    }else{
        rank[b]++;
        parent[a]=b;
    }
   }
 
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int val=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push({val,i,j});
            }
        }
        vector<int>parent(n);
        for(int i=0;i<n;i++)parent[i]=i;
        vector<int>rank(n,1);
        int ans=0;
        int noofedge=0;
        while(noofedge<n-1 and !edges.empty()){
            auto x=edges.top();
            edges.pop();
            int src=x[1];
            int dest=x[2];
            if(find(parent,src)!=find(parent,dest)){
                Union(parent,rank,src,dest);
                ans+=x[0];
                noofedge++;
            }
        }

    return ans;
    }
};