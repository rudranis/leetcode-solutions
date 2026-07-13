class Solution {
public:
    bool candistribute(const vector<int>&candies,long long perchild,long long k){
        if(perchild==0) return true;
        long long total=0;
        for(int pile:candies){
            total+=(pile/perchild);
        }
        return total>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low=0;
        int high=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(candistribute(candies,mid,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }        
        return ans;
    }
};
