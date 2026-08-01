class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int,unordered_map<int,int>>mp;
        for(auto &p : pick){
            int player=p[0];
            int color=p[1];
            mp[player][color]++;
        }
        int ans=0;
        for(int player=0;player<n;player++){
            int maxfreq=0;
            for(auto &it :mp[player]){
                maxfreq=max(maxfreq,it.second);
            }
            if(maxfreq>player){
                ans++;
            }
        }
        return ans;
    }
};
