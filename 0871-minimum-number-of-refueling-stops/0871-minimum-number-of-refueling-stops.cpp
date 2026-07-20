class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;

        stations.push_back({target, 0});

        int fuel = startFuel;
        int prev = 0;
        int stops = 0;

        for (auto &station : stations) {

            int position = station[0];
            int gas = station[1];

            fuel -= (position - prev);

            while (fuel < 0) {

                if (pq.empty())
                    return -1;

                fuel += pq.top();
                pq.pop();

                stops++;
            }

            pq.push(gas);

            prev = position;
        }

        return stops;
    }
};