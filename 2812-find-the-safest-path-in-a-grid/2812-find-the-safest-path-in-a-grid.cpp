class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        //all thieves push 
        for(int i=0;i<n;i++){   
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        //multisource bfs for calculate distance from theives 
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nc>=0 && nr<n && nc<n && dist[nr][nc]==INT_MAX){
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }

        }

        //maxheap 
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>best(n,vector<int>(n,-1));
        best[0][0]=dist[0][0];
        pq.push({dist[0][0],{0,0}});
        //modified dijstraka
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int safe=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1&& c==n-1){
                return safe;
            }
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nc>=0 && nr<n&&nc<n){
                    int newsafe=min(safe,dist[nr][nc]);
                    if(newsafe>best[nr][nc]){
                        best[nr][nc]=newsafe;
                        pq.push({newsafe,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};