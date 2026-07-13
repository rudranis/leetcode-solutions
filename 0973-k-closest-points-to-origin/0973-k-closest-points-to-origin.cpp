class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxheap;
        for(const auto & point:points){
            int x=point[0];
            int y=point[1];
            int squaredis=x*x+y*y;
            maxheap.push({squaredis,point});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        vector<vector<int>>res;
        while(!maxheap.empty()){
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return res;
    }
};      