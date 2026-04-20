class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || j<0 ||i>=m||j>=n ||grid[i][j]==0)
            return 0;
        int fish=grid[i][j];
        grid[i][j]=0;
        return fish
            +dfs(grid,i+1,j)
            +dfs(grid,i-1,j)
            +dfs(grid,i,j+1)
            +dfs(grid,i,j-1);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0)
                {
                    int total=dfs(grid,i,j);
                    maxi=max(maxi,total);
                }
            }
        }
        return maxi;
    }
};