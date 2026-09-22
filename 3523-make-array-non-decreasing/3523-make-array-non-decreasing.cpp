class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int>st;
        for(int x:nums){
            int cur=x;
            while(!st.empty() && st.back() > cur){
                cur=max(cur,st.back());
                st.pop_back();
            }
            st.push_back(cur);
        }
        return st.size();
    }
};
