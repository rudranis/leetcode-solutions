class Solution {
public:
    int dfs(vector<int>&nums,int index,int currxor)
    {
        if(index==nums.size())
            return currxor;
        int include=dfs(nums,index+1,currxor^nums[index]);
        int exclude=dfs(nums,index+1,currxor);
        return include+exclude;//manje include - left ani exclude - right
    }
    int subsetXORSum(vector<int>& nums) {
       return dfs(nums,0,0); 
    }
};