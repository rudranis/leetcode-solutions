class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>grid(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;
        for( auto &s: sources){
            int r=s[0];
            int c=s[1];
            int color=s[2];
            grid[r][c]=color;
            q.push({r,c,color});
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            int sz=q.size();
            unordered_map<int,int>best;
            while(sz--){
                auto[r,c,color]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr<0 || nr>=n|| nc<0 ||nc>=m){
                        continue;
                    }
                    if(grid[nr][nc]==0){   // Only uncolored cells
                        int id=nr*m+nc;
                        best[id]=max(best[id],color);
                    }
                }
            }
            for(auto &[id,color]:best){
                int r=id/m;
                int c=id%m;
                if(grid[r][c]==0){
                    grid[r][c]=color;
                    q.push({r,c,color});
                }
            }
        }
        return grid;
    }
};

