class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int curtime=0,time=0;
        for(int i=0;i<requests.size();i++){
            time+=abs(curtime-requests[i]);
            curtime=requests[i];
        }
        return time;
    }
};