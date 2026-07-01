class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int keep=arr[0];
        int drop=INT_MIN;
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            int newdrop;
            if(drop==INT_MIN)
                newdrop=keep;
            else
                newdrop=max(keep,drop+arr[i]);
            int newkeep=max(arr[i],keep+arr[i]);
            keep=newkeep;
            drop=newdrop;
            ans=max(ans,max(keep,drop));
        }
        return ans;
    }
};