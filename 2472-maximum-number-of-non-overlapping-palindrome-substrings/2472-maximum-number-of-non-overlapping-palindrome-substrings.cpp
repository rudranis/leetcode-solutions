class Solution {
public:
    int maxPalindromes(string s, int k) {

        int n = s.size();

        // isPal[l][r] = true if s[l...r] is palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Build palindrome DP
        for (int len = 1; len <= n; len++) {

            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                if (len == 1) {
                    isPal[l][r] = true;
                }
                else if (len == 2) {
                    isPal[l][r] = (s[l] == s[r]);
                }
                else {
                    isPal[l][r] =
                        (s[l] == s[r]) &&
                        isPal[l + 1][r - 1];
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // using first i characters
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Option 1: don't take a palindrome ending here
            dp[i] = dp[i - 1];

            // Try every starting point j
            for (int j = 0; j < i; j++) {

                int len = i - j;

                if (len >= k && isPal[j][i - 1]) {

                    // Take s[j...i-1]
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};