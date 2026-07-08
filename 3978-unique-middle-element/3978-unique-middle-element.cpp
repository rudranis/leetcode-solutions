class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int s:nums){
            mp[s]++;
        }
        int mid=nums.size()/2;
        if(mp[nums[mid]]==1){
            return true;
        }
        return false;
    }
};