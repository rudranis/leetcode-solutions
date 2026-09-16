class Solution {
public:
    static const int MOD = 1000000007;

    int numberOfSets(int n, int k) {

        vector<long long> dp(n, 1);
        vector<long long> prefix(n + 1, 0);

        // dp[j] = 1 when we need 0 segments
        for (int j = 0; j < n; j++) {
            prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
        }

        for (int segments = 1; segments <= k; segments++) {

            dp[0] = 0;

            for (int j = 1; j < n; j++) {

                // Skip point j
                // + Start a segment ending at j
                dp[j] = (dp[j - 1] + prefix[j]) % MOD;
            }

            // Recalculate prefix sums
            prefix[0] = 0;

            for (int j = 0; j < n; j++) {
                prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
            }
        }

        return dp[n - 1];
    }
};