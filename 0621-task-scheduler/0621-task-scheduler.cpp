class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> freq;

        for(char task : tasks)
            freq[task]++;

        priority_queue<int> pq;

        for(auto &it : freq)
            pq.push(it.second);

        queue<pair<int,int>> cool;

        int time = 0;

        while(!pq.empty() || !cool.empty()) {

            time++;

            if(!pq.empty()) {
                int cnt = pq.top();
                pq.pop();

                cnt--;

                if(cnt > 0)
                    cool.push({cnt, time + n});   
            }

            if(!cool.empty() && cool.front().second == time) {
                pq.push(cool.front().first);
                cool.pop();
            }
        }

        return time;
    }
};