class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push({freq[i],char(i+'a')});
            }
        }
        string ans="";
        pair<int,char>prev={0,'#'};
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            ans+=cur.second;
            cur.first--;
            if(prev.first>0){
                pq.push(prev);
            }
            prev=cur;
            
        }
        if(ans.size()!=s.size()){
            return "";
        }
        return ans;
    }
};