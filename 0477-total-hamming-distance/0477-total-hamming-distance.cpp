class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int b=0;b<32;b++){
            int ones=0;
            for(int num:nums){
                if(num & (1<<b)){
                    ones++;
                }
            }
            ans+=ones*(n-ones);
        }
        return ans;
    }
};
