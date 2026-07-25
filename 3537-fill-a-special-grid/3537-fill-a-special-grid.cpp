class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
 
        if (n == 0)
            return {{0}};

        vector<vector<int>> small = specialGrid(n - 1);

        int m = small.size();         
        int size = 2 * m;              
        int block = m * m;            
        vector<vector<int>> ans(size, vector<int>(size));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j + m] = small[i][j];
                ans[i + m][j + m] = small[i][j] + block;
                ans[i + m][j] = small[i][j] + 2 * block;
                ans[i][j] = small[i][j] + 3 * block;
            }
        }

        return ans;
    }
};