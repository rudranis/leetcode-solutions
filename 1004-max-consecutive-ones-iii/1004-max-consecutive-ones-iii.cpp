class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,zerocnt=0,maxlen=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0){
                zerocnt++;
            }
            while(zerocnt>k){
                if(nums[l]==0){
                    zerocnt--;
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};