class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        int target=total-x;
        if(target<0) return -1;
        int l=0,sum=0,maxlen=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(l<=i && sum>target){
                sum-=nums[l];
                l++;
            }
            if(sum==target) maxlen=max(maxlen,i-l+1);
        }
        if(maxlen==-1) return -1;
        return n-maxlen;  //5-3=2
    }
};