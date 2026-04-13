class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int total=n*n;
        int repeat=-1;
        long long actualSum=0;
        unordered_map<int,int>mp;
        for(auto&r:grid)  //aadhi grid che row read karun natar row che val 
        {
            for(auto&val:r)
            {
                mp[val]++;
                actualSum+=val;
            }
        }
        for(int i=1;i<=total;i++)
        {
            if(mp[i]==2) repeat=i;
        }
        long long expectedSum = (long long)total * (total + 1) / 2;
        int missing = repeat - (actualSum - expectedSum);
        return {repeat,missing};
    }
};