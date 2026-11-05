
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;

        for (int x : arr1) {
            int i = 0;
            int j = arr2.size() - 1;
            bool valid = true;

            while (i <= j) {
                int mid = i + (j - i) / 2;

                if (abs(x - arr2[mid]) <= d) {
                    valid = false;
                    break;
                }
                else if (arr2[mid] < x - d) {
                    i = mid + 1;
                }
                else {
                    j = mid - 1;
                }
            }

            if (valid) ans++;
        }

        return ans;
    }
};
