class Solution {
public:
    struct mycomparator{
        bool operator()(const pair<int,string>&a,const pair<int,string>&b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;
        for(const string & word:words){
            freq[word]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,mycomparator>minheap;
        for(auto & pair:freq){
            minheap.push({pair.second,pair.first});
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        vector<string>res(k);
        for(int i=k-1;i>=0;i--){
            res[i]=minheap.top().second;
            minheap.pop();
        }
        return res;
    }
};