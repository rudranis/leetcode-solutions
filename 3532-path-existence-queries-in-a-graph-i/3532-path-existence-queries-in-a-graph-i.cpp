class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>comp(n);
        for(int i=1;i<n;i++){
            comp[i]=comp[i-1]+(nums[i]-nums[i-1]>maxDiff);
        }
        vector<bool>res;
        for(auto &q:queries){
            res.push_back(comp[q[0]]==comp[q[1]]);
        }
        return res;
    }
};