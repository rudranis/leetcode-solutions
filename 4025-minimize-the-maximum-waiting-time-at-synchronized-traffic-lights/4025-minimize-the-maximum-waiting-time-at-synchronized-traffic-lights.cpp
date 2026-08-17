class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxi=*max_element(lights.begin(),lights.end());
        int penality=0;
        for(int i=0;i<arrivalTime.size();i++){
            int r=arrivalTime[i]%period;
            if(r<maxi) penality=max(penality,0);
            else penality=max(penality,period-r);
        }
        return penality;
    }
};