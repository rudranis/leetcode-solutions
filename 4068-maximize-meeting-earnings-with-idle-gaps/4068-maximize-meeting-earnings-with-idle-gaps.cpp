class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        
        // Sort meetings by end time
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int n = meetings.size();

        vector<long long> dp(n);
        vector<long long> best(n);

        for (int i = 0; i < n; i++) {

            long long start = meetings[i][0];
            long long end = meetings[i][1];
            long long revenue = meetings[i][2];

            // Take only this meeting
            dp[i] = revenue;

            // Find last meeting whose end <= current start
            int left = 0, right = i - 1;
            int pos = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (meetings[mid][1] <= start) {
                    pos = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            // Previous meetings + gap + current meeting
            if (pos != -1) {
                dp[i] = max(
                    dp[i],
                    best[pos] + start + revenue
                );
            }

            // best[i] = max(dp[j] - end[j])
            if (i == 0) {
                best[i] = dp[i] - end;
            } else {
                best[i] = max(
                    best[i - 1],
                    dp[i] - end
                );
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};