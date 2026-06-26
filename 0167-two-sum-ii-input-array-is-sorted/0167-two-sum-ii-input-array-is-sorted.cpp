class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        int sum=0;
        while(l<r){
            sum=numbers[l]+numbers[r];

            if(sum<target){
                l++;
            }
            else if(sum>target){
                r--;
            }
            else{
                return {l+1,r+1};
            }
        }
        return {-1,-1};
    }
};