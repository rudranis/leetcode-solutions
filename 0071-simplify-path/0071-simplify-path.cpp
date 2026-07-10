class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string curr="";
        for(int i=0;i<=path.size();i++){
          if(i==path.size()|| path[i]=='/'){
                if(curr == "" || curr == ".") {
                //ignore kara
            }
            else if(curr==".."){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(curr);
            }
            curr="";
          }
          else{
            curr+=path[i];
          }
        }
        vector<string>temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        string ans="";
        for(string s:temp){
            ans+="/"+s;
        }
        if(ans=="")
            return "/";
        return ans;

    }
};
