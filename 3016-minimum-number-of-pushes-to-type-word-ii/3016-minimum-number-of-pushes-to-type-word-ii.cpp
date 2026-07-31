class Solution {
public:
    int minimumPushes(string word) {
         vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        priority_queue<int> pq;

        for (int f : freq)
            if (f > 0)
                pq.push(f);

        int ans = 0;
        int cnt = 0;

        while (!pq.empty()) {
            ans += pq.top() * ((cnt / 8) + 1);
            pq.pop();
            cnt++;
        }

        return ans;
    }
};