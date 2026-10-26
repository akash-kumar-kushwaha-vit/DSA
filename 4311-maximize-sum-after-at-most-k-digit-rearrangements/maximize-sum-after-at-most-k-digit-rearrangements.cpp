class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {

        vector<pair<int, int>> gains;
        long long sum = 0;

        for (int num : nums) {

            sum += num;

            string s = to_string(num);

            sort(s.begin(), s.end(), greater<char>());

            int maxi = stoi(s);

            int gain = maxi - num;

            gains.push_back({gain, maxi});
        }

        sort(gains.begin(), gains.end(),
             greater<pair<int, int>>());

        for (int i = 0; i < k; i++) {
            sum += gains[i].first;
        }

        return sum;
    }
};