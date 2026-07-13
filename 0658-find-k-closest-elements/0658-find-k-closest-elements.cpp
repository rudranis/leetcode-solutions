class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>maxheap;
        for(int num:arr){
            int diff=abs(num-x);
            maxheap.push({diff,num});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        vector<int>res;
        while(!maxheap.empty()){
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};      
      