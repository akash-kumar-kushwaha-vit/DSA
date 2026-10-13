class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i=0;
        int j=0;
        int n=asteroids.size();
        while(j<n){
            if(asteroids[j]<0){
                int k=j-1;
                while(k>=0 && asteroids[k]>=0){
                    if(asteroids[k]==abs(asteroids[j])){
                        asteroids[k]=0;
                        asteroids[j]=0;
                    }
                    else if(asteroids[k]<abs(asteroids[j])){
                        asteroids[k]=0;
                    }else{
                        asteroids[j]=0;
                        break;
                    }
                    k--;
                }
                i=j+1;

            }
            j++;
        }
         vector<int>ans;
        for(int x:asteroids){
            if(x!=0)ans.push_back(x);
        }
        return ans;

    }
};