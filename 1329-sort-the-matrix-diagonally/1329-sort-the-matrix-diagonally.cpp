class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
        }
        unordered_map<int,int>idx;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = mp[i-j][idx[i-j]];
                idx[i-j]++;
            }
        }
        return mat;

    }
}; 
      
