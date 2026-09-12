class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        sort(events.begin(),events.end());
        int maxval=0,maxsum=0;
        for(auto & event:events){
            while(pq.size() && pq.top().first < event[0]){
                maxval=max(maxval,pq.top().second);
                pq.pop();
            }
            maxsum=max(maxsum,maxval+event[2]);
            pq.push({event[1],event[2]});
        }
        return maxsum;
    }
};