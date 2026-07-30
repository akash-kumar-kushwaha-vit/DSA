class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        cout<<n;
        int cost=0;
        int x=0;
        while(n>=8){
            cost+=(8+x*8);
            n-=8;
            x++;
        }
        cost+=(n+n*x);
        return cost;
    }
};