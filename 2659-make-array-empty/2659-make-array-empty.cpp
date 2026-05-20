class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        sort(v.begin(), v.end());

        long long ans = n;

        for(int i = 1; i < n; i++) {

            if(v[i].second < v[i - 1].second)
                ans += (n - i);
        }

        return ans;
    }
};