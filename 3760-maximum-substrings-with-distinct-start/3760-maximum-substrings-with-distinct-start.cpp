class Solution {
public:
    int maxDistinct(string s) {
        vector<bool>seen(26,false);
        for(char c:s)
        {
            seen[c-'a']=true;
        }
        int cnt=0;
        for(bool x:seen)
        {
            if(x) cnt++;
        }
        return cnt;
    }
};