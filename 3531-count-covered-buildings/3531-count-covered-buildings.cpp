class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,vector<int>>rows;
        unordered_map<int,vector<int>>cols;
        for(auto &b:buildings){
            int x=b[0];
            int y=b[1];
            rows[x].push_back(y);
            cols[y].push_back(x);
        }
        for(auto &it:rows){
            sort(it.second.begin(),it.second.end());
        }
        for(auto &it:cols){
            sort(it.second.begin(),it.second.end());
        }
        int ans=0;
        for(auto &b:buildings){
            int x=b[0];
            int y=b[1];
            auto &row=rows[x];
            auto &col=cols[y];
            int rowpos=lower_bound(row.begin(),row.end(),y)-row.begin();
            int colpos=lower_bound(col.begin(),col.end(),x)-col.begin();
            if(rowpos>0 && rowpos<row.size()-1 && colpos>0 && colpos<col.size()-1){
                ans++;
            }
        }
        return ans;

    }
};