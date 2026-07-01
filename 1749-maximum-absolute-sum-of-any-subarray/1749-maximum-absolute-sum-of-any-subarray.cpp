class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curmax=nums[0];
        int maxsum=nums[0];
        int curmin=nums[0];
        int minsum=nums[0];
        for(int i=1;i<nums.size();i++){
            curmax=max(nums[i],curmax+nums[i]);
            maxsum=max(maxsum,curmax);
            curmin=min(nums[i],curmin+nums[i]);
            minsum=min(minsum,curmin);
        }
        return max(maxsum,abs(minsum));
    }
};