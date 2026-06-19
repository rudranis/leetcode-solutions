class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>arr(n+1);
        arr[0]=0;
        
        for(int i=0;i<n;i++){
            int diff=arr[i]+gain[i];
            arr[i+1]=diff;
        }
        int max=0;
        for(int i=0;i<=n;i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;

    }
};