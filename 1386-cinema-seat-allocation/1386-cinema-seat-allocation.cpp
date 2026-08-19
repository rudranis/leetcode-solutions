class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, unordered_set<int>> mp;
        for (auto &v : reservedSeats) {
            mp[v[0]].insert(v[1]);
        }

        // Rows with no reservations
        int ans = (n - mp.size()) * 2;

        for (auto &[row, seats] : mp) {

            bool A = true;   // 2 3 4 5
            bool B = true;   // 4 5 6 7
            bool C = true;   // 6 7 8 9

            for (int i = 2; i <= 5; i++) {
                if (seats.count(i))
                    A = false;
            }

            for (int i = 4; i <= 7; i++) {
                if (seats.count(i))
                    B = false;
            }

            for (int i = 6; i <= 9; i++) {
                if (seats.count(i))
                    C = false;
            }

            if (A && C)
                ans += 2;
            else if (A || B || C)
                ans += 1;
        }

        return ans;
    }
};