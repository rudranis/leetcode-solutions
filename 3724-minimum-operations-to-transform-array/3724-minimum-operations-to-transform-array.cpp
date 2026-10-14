class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans=0;
        int n=nums1.size();
        long long extra=LLONG_MAX;
        int target=nums2[n];
        for(int i=0;i<n;i++){
            int a=nums1[i];
            int b=nums2[i];
            ans+=abs(a-b);
            int low=min(a,b);
            int high=max(a,b);
            if(target>=low && target <=high){
                extra=1;
            }
            else{
                extra=min(extra,(long long)min(abs(target-a),abs(target-b))+1);
            }
        }
        return ans+extra;
    }
};
