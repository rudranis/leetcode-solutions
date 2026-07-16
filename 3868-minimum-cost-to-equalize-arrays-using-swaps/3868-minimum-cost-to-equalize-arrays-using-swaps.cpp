class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt1, cnt2, total;

        for (int x : nums1) {
            cnt1[x]++;
            total[x]++;
        }

        for (int x : nums2) {
            cnt2[x]++;
            total[x]++;
        }

        int diffSum = 0;

        for (auto &[val, freq] : total) {
            if (freq % 2)
                return -1;

            diffSum += abs(cnt1[val] - cnt2[val]);
        }

        return diffSum / 4;
    }
};