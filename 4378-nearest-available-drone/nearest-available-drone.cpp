class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int manhd=INT_MAX;
        int n=drones.size();
        int midx=INT_MAX;
        
        for(int i=0;i<n;i++){
           int t=abs(target[0]-drones[i][0])+abs(target[1]-drones[i][1]);
           if(manhd==t){
            midx=min(midx,i);
           }
          else  if(manhd>t && drones[i][2]>=t){
            manhd=t;
            midx=i;
           }
        }
        return midx==INT_MAX?-1:midx;
    }
};