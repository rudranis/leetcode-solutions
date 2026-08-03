class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
          int n = stoneValue.size();

        vector<int> dp(n + 3, 0);

        for (int i = n - 1; i >= 0; i--) {

            int take = stoneValue[i];
            int ans = take - dp[i + 1];

            if (i + 1 < n) {
                take += stoneValue[i + 1];
                ans = max(ans, take - dp[i + 2]);
            }

            if (i + 2 < n) {
                take += stoneValue[i + 2];
                ans = max(ans, take - dp[i + 3]);
            }

            dp[i] = ans;
        }

        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] < 0)
            return "Bob";

        return "Tie";
    }
};