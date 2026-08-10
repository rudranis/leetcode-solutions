class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<long long> depth(n);
        
        depth[0] = 1;
        long long ht = 1;
        long long sum = 0;

        for(int i = 0; i < n; i++){
            if(depth[i] == 0)
                Fn(i, parent, depth);

            ht = max(ht, depth[i]);
        }

        for(int i = 0; i < n; i++){
            sum += 1LL * nums[i] * (ht - depth[i] + 1);
        }

        return sum;
    }

private:
    long long Fn(int node, vector<int>& parent, vector<long long>& depth){
        if(parent[node] == -1)
            return 1;

        if(depth[node] != 0)
            return depth[node];

        return depth[node] =
            Fn(parent[node], parent, depth) + 1;
    }
};