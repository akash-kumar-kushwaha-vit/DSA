class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> v;

        for (int x : nums) {
            int sum = 0;
            int temp = x;

            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            v.push_back({sum, x});
        }

        vector<pair<int, int>> sorted = v;
        sort(sorted.begin(), sorted.end());
       

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] == sorted[i]) continue;

            ans++;
            int j = pos[sorted[i].second];

            pos[v[i].second] = j;
            pos[sorted[i].second] = i;

            swap(v[i], v[j]);
        }

        return ans;
    }
};