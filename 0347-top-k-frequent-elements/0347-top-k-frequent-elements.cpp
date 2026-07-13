class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        for(auto &pair:freq){
            int ele=pair.first;
            int freq=pair.second;
            minheap.push({freq,ele});
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        vector<int>res;
        while(!minheap.empty()){
            res.push_back(minheap.top().second);
            minheap.pop();
        }
        return res;
    }
};