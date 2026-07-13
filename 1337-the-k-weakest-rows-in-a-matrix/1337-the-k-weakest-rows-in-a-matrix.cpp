class Solution {
public:
    int countsoldier(const vector<int>&row){
        int low=0,high=row.size()-1;
        int firstzeroindex=row.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(row[mid]==0){
                firstzeroindex=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return firstzeroindex;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>maxheap;
        for(int i=0;i<mat.size();i++){
            int soldiers=countsoldier(mat[i]);
            maxheap.push({soldiers,i});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        vector<int>res(k);
        for(int i=k-1;i>=0;i--){
            res[i]=maxheap.top().second;
            maxheap.pop();
        }
        return res;
    }
};
