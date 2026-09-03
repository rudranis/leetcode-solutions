class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
         
        vector<int> maxReach(n + 1, 0);

        // Convert every tap into an interval
        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);

            maxReach[left] = max(maxReach[left], right);
        }

        int taps = 0;
        int currentEnd = 0;
        int farthest = 0;

        // Greedy traversal
        for (int i = 0; i <= n; i++) {

            farthest = max(farthest, maxReach[i]);

            // Current coverage has ended
            if (i == currentEnd) {

                // Cannot cover further
                if (farthest <= i)
                    return -1;

                // Open one more tap
                taps++;
                currentEnd = farthest;

                // Entire garden covered
                if (currentEnd >= n)
                    return taps;
            }
        }

        return -1;
    }
};