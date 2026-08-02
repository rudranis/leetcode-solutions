class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        int ans=0;
        for(int l=0;l<n;l++){
            int e=0,o=0;
            for(int r=l;r<n;r++){
                if(nums[r]%2==0)
                    e++;
                else
                    o++;
                if(o >0 && 1LL *b*e<=1LL*a*o)
                    ans++;
            }
        }
        return ans;
    }
};