class Solution {
public:
    int smallestNumber(int n, int t) {
        if(t==1)return n;
        int ans = 1;

        while (ans % t != 0) {
            int on=n;
            ans=1;
            while (on > 0) {
                ans = ans * (on % 10);
                on = on / 10;
            }
             n++;
        }
        return n-1;
    }
};