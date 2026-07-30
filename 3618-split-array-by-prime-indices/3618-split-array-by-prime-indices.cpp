class Solution {
public:
    bool isprime(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        vector<int>p;
        vector<int>np;
        for(int i=0;i<nums.size();i++){
            if(isprime(i)){
                p.push_back(nums[i]);
            }
            else{
                np.push_back(nums[i]);
            }
        }
        long long sum1=0,sum2=0;
        for(int x:p){
            sum1+=x;
        }
        for(int x:np){
            sum2+=x;
        }
        return abs(sum1-sum2);

    }
};
