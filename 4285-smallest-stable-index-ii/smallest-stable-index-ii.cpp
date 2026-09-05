class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int maxidx = 0;
        int minisv = INT_MAX;
        int minisidx = -1;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > mh;

        // Store {value, index}
        for (int i = 0; i < n; i++) {
            mh.push({nums[i], i});
        }

        for (int i = 0; i < n; i++) {

            // Remove elements which are before current index
            while (!mh.empty() && mh.top().second < i) {
                mh.pop();
            }

            if (mh.empty())
                break;

            auto p = mh.top();

            int diff;

            // Update maximum
            if (nums[i] > nums[maxidx]) {
                maxidx = i;
            }

            // p.first = minimum value
            diff = nums[maxidx] - p.first;

            if (diff <= k && diff < minisv) {
                minisv = diff;
                minisidx = i;
                return i;
            }
        }

        // if (minisidx == 0 && n > 1) {
        //     if (nums[0] == nums[maxidx])
        //         return -1;
        // }

        return minisidx;
    }
};