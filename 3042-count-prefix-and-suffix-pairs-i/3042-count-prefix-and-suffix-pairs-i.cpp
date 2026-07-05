class Solution {
public:
    bool check(string a, string b){
        int n=a.size();
        int m=b.size();
        if(n>m) return false;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i])return false;
        }
        for(int i=0;i<n;i++){
            if(a[i]!=b[m-n+i]) return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(check(words[i],words[j]))
                    cnt++;
            }
        }
        return cnt;
    }
};
