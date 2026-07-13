class Solution {
public:
    int countlessequal(int m,int n,int mid){
        int cnt=0;
        for(int i=1;i<=m;i++){
            cnt+=min(n,mid/i);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int low=1,high=m*n;
        while(low<high){
            int mid=low+(high-low)/2;
            if(countlessequal(m,n,mid)>=k){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }        
        return low;
    }
};
