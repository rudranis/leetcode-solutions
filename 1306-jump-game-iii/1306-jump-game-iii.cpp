class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int>q;
        vector<bool>vis(n,false);
        q.push(start);
        vis[start]=true;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(arr[i]==0) return true;
            int forw=i+arr[i];
            int bac=i-arr[i];
            if(forw<n && !vis[forw]){
                vis[forw]=true;
                q.push(forw);
            }
            if(bac>=0 && !vis[bac]){
                vis[bac]=true;
                q.push(bac);
            }
        }
        return false;
    }
};