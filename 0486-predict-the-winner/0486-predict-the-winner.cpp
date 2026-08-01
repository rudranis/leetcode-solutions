class Solution {
public:
     vector<vector<int>> dp;

    int solve(int l, int r, vector<int>& nums) {

        if (l == r)
            return nums[l];

        if (dp[l][r] != -1)
            return dp[l][r];

        int left = nums[l] - solve(l + 1, r, nums);

        int right = nums[r] - solve(l, r - 1, nums);

        return dp[l][r] = max(left, right);
    }
    bool predictTheWinner(vector<int>& nums) {
         int n = nums.size();

        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1, nums) >= 0;
    }
};