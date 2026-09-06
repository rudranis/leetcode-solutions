class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long rsum=0;
        long long lsum=0;
        int cnt=0;
        int h=n/2;
        for(int i=0; i<n/2; i++){
            lsum=lsum+nums[i];
        }
        for(int i=h;i<n;i++){
            rsum=rsum+nums[i];
        }
        for(int i=0;i<n;i++){
            if(lsum>rsum){
                cnt++;
            }
            int j=(i+h)%n;
            lsum=lsum-nums[i]+nums[j];
            rsum=rsum-nums[j]+nums[i];
        }
        return cnt;

    }
};