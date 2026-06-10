class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
         int n = timeSeries.size();
        int total = 0;

        for (int i = 0; i < n - 1; i++) {
            total += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }

        return total + duration;
    }
};