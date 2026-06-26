class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int l=0,r=nums.size()-1;
        int k=r;
        while(l<=r){
            int ls=nums[l]*nums[l];
            int rs=nums[r]*nums[r];
            if(ls>rs){
                ans[k]=ls;
                k--;
                l++;
            }
            
            else{
                ans[k]=rs;
                k--;
                r--;
            }
           

        }
        return ans;
    }
};