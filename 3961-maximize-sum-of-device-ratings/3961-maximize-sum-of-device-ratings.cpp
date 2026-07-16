class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units[0].size();

        if (n == 1) {
            long long ans = 0;
            for (auto &row : units)
                ans += row[0];
            return ans;
        }

        long long sumSecond = 0;
        int globalMin = INT_MAX;
        int smallestSecond = INT_MAX;

        for (auto &row : units) {
            int mn = INT_MAX;
            int sec = INT_MAX;

            for (int x : row) {
                if (x < mn) {
                    sec = mn;
                    mn = x;
                } else if (x < sec) {
                    sec = x;
                }
            }

            globalMin = min(globalMin, mn);
            smallestSecond = min(smallestSecond, sec);
            sumSecond += sec;
        }

        return sumSecond - smallestSecond + globalMin;
    }
};