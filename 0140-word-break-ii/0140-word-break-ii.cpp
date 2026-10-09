class Solution {
public:
    unordered_set<string>dict;
    unordered_map<int,vector<string>>memo;
    vector<string>solve(string & s,int start){
        if(memo.count(start)){
            return memo[start];
        }
        vector<string>ans;
        if(start==s.size()){
            ans.push_back("");
            return ans;
        }
        for(int end=start+1;end<=s.size();end++){
            string word=s.substr(start,end-start);
            if(dict.count(word)){
                vector<string>suffixs=solve(s,end);
                for(string suffix :suffixs){
                    if(suffix.empty()){
                        ans.push_back(word);
                    }
                    else{
                        ans.push_back(word+" "+suffix);
                    }
                }
            }
        }
        return memo[start]=ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string word:wordDict){
            dict.insert(word);
        }
        return solve(s,0);
    }

};