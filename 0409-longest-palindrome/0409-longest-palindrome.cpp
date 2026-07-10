class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        for(char ch:s){
            freq[ch]++;
        }
        int ans=0;
        bool oddfound=false;
        for(auto it:freq){
            if(it.second%2==0){  //even frequency
                ans+=it.second;
            }
            else{    //odd frequency 
                ans+=it.second-1;
                oddfound=true;
            }
        }
        if(oddfound) 
            ans++;

        return ans;
    }
};