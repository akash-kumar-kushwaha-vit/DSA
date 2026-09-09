class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000)
            return 0;

        long long tn = 1000;
        long long ans = 0;
        long long c = 1;

        while (tn <= n) {
            long long end = min(n, tn * 1000 - 1);

            long long count = end - tn + 1;

            ans += count * c;

            tn *= 1000;
            c++;
        }

        return ans;
    }
};