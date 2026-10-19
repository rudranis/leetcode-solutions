class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<bool> know(n, false);
        know[0] = true;
        know[firstPerson] = true;

        int i = 0;

        while (i < meetings.size()) {
            int time = meetings[i][2];

            unordered_map<int, vector<int>> graph;
            unordered_set<int> people;

            while (i < meetings.size() && meetings[i][2] == time) {
                int x = meetings[i][0];
                int y = meetings[i][1];

                graph[x].push_back(y);
                graph[y].push_back(x);

                people.insert(x);
                people.insert(y);
                i++;
            }

            queue<int> q;
            unordered_set<int> visited;

            for (int person : people) {
                if (know[person]) {
                    q.push(person);
                    visited.insert(person);
                }
            }

            while (!q.empty()) {
                int person = q.front();
                q.pop();

                know[person] = true;

                for (int next : graph[person]) {
                    if (!visited.count(next)) {
                        visited.insert(next);
                        know[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (know[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};