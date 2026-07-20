class Solution {
public:

    void solve(vector<int>& nums,
               vector<bool>& used,
               vector<int>& curr,
               vector<vector<int>>& ans) {

        // Base Case
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(used[i])
                continue;

            // Choose
            curr.push_back(nums[i]);
            used[i] = true;

            // Explore
            solve(nums, used, curr, ans);

            // Backtrack (Undo)
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size(), false);

        solve(nums, used, curr, ans);

        return ans;
    }
};