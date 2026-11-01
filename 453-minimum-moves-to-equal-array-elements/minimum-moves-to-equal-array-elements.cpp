class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minx=INT_MAX;
        long long sum=0;
        for(int x:nums){
           sum+=x;
           minx=min(minx,x);
        }
        return sum-nums.size()*minx;
    }
};