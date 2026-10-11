
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        int i = 1;

        while (i < n) {
            if (colors[i] == colors[i - 1]) {
                if (neededTime[i] < neededTime[i - 1]) {
                    ans += neededTime[i];
                    neededTime[i] = neededTime[i - 1];
                } else {
                    ans += neededTime[i - 1];
                }
            }
            i++;
        }

        return ans;
    }
};
