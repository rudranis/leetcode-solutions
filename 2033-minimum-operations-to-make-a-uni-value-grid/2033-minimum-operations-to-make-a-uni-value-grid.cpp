class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(auto &row : grid) {
            for(int val : row) {
                arr.push_back(val);
            }
        }

        int rem = arr[0] % x;
        for(int val : arr) {
            if(val % x != rem)
                return -1;
        }
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int median = arr[n / 2];
        int ops = 0;
        for(int val : arr) {
            ops += abs(val - median) / x;
        }

        return ops;
    }
};