class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a , vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int cnt=0;
        int maxend=-1;
        for(auto &intervals:intervals){
            if(intervals[1]>maxend){
                cnt++;
                maxend=intervals[1];
            }

        }
        return cnt;
    }
};
