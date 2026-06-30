class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int cnt=0;
        int n=s.size();
        unordered_map<char,int>mp;
        for(int r=0;r<s.size();r++){
            mp[s[r]]++;
           while((mp['a']>0) && (mp['b']>0) &&( mp['c']>0))
           {
            cnt+=(n-r); 
            mp[s[l]]--;
            l++;
           }
        }
        return cnt;
    }
};