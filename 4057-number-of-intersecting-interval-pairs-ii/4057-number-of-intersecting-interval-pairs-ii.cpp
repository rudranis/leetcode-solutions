class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        auto t=intervals;
        int n=t.size();
        vector<int>start;
        vector<int>end;
        for(auto & interval:t){
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        long long ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<i && end[j] <start[i]){
                j++;
            }
            ans+=i-j;
        }
        return ans;
    }
};