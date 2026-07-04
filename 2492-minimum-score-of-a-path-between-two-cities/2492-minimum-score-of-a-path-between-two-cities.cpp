class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    vector<int>vis;
    int ans=INT_MAX;
    void dfs(int node){
        vis[node]=1;
        for(auto it:adj[node]){
            int next=it.first;
            int wt=it.second;
            ans=min(ans,wt);
            if(!vis[next]){
                dfs(next);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        adj.resize(n+1);
        vis.assign(n+1,0);
        for(auto &it:roads){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        dfs(1);
        return ans;
    }
};