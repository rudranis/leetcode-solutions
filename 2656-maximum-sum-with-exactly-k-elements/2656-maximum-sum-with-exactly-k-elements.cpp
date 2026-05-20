class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int x:nums){
            pq.push(x);
        }
        long long score=0;
        while(k--){
            int top=pq.top();
            pq.pop();
            score+=top;
            pq.push(top+1);
        }
        return score;
    }
};