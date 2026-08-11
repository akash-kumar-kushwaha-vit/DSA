class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        // Find sequential prefix sum
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Store all numbers present in nums
        unordered_set<int> st;

        for (int x : nums) {
            st.insert(x);
        }

        // Find smallest missing integer >= sum
        int ans = sum;

        while (st.count(ans)) {
            ans++;
        }

        return ans;
    }
};