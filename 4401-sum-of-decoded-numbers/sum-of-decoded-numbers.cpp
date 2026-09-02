class Solution {
public:
    const long long MOD = 1000000007LL;

    long long power(long long x, long long y) {
        long long ans = 1;
        x %= MOD;

        while (y > 0) {
            if (y & 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            y /= 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;

        for (long long num : nums) {
            int w=(num%10);
            long long d = num / 10;

            string s = to_string(d);

            long long x = stoll(s.substr(0, w));
            long long y = stoll(s.substr(w));

            sum = (sum + power(x, y)) % MOD;
        }

        return sum;
    }
};