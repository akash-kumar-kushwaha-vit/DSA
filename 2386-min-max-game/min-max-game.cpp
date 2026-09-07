class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return nums[0];
        int newarr[n / 2];
        while (n > 1) {
            for (int i = 0; i < n / 2; i++) {
                if (i % 2 == 0) {
                    newarr[i] = min(nums[2 * i], nums[2 * i + 1]);
                } else {
                    newarr[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
            }
            for (int i = 0; i < n / 2; i++)
                nums[i] = newarr[i];
            n /= 2;
        }
        return nums[0];
    }
};