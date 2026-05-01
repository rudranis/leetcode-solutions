class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        long sum=0;
        long f=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            f+=i*nums[i];
        }
        long maxval=f;
        for(int k=1;k<n;k++)
        {
            f=f+sum-n*nums[n-k];
            maxval=max(maxval,f);
        }
        return (int)maxval;
    }
};