class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n=arr.size();
        vector<int>arr1=arr;
        sort(arr1.begin(),arr1.end());
        unordered_map<int, int> rank_mp;
        int rank=1;
        for(int num:arr1){
            if(rank_mp.find(num)==rank_mp.end()){
                rank_mp[num]=rank;
                rank++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=rank_mp[arr[i]];
        }
        return arr;


    }
};
