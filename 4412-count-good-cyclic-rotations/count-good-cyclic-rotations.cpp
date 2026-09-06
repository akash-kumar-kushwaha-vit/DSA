class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long lsum = 0;
        long long rsum = 0;
        int ans = 0;
        int n = nums.size();
        for (int i = n / 2; i < n; i++) {
            rsum += nums[i];
        }
        for (int i = 0; i < n / 2; i++) {
            lsum += nums[i];
        }
        int i = 0, j = n / 2;
        if(lsum<rsum)ans++;
        while (j < n) {
            lsum = (lsum - nums[i] + nums[j]);
            rsum = (rsum - nums[j] + nums[i]);
             if (lsum < rsum)
                ans++;
            i++;
            j++;
        }
        i=0,j=n/2;
         while (j < n-1) {
            lsum = (lsum - nums[j] + nums[i]);
            rsum = (rsum - nums[i] + nums[j]);
             if (lsum < rsum)
                ans++;
            i++;
            j++;
        }
        


        return ans;
    }
};