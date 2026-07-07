class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>x;
        for(auto & p:points){
            x.push_back(p[0]);
        }
        sort(x.begin(),x.end());
        int mmaxi=0;
        for(int i=1;i<x.size();i++){
            mmaxi=max(mmaxi,x[i]-x[i-1]);
        }
        return mmaxi;
    }
};