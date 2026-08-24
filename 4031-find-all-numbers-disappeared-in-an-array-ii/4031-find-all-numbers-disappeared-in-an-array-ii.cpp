class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
         vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        long long prev = (long long)lower - 1;
        
        for (int num : nums) {
            
            if (num < lower || num > upper)
                continue;
            
            if (num - prev > 1) {
                ans.push_back({(int)prev + 1, num - 1});
            }
            
            prev = num;
        }
        
        if (upper - prev >= 1) {
            ans.push_back({(int)prev + 1, upper});
        }
        
        return ans;
    }
};