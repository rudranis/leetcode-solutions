class Solution {
public:
    string findLatestTime(string time) 
    {
        string ans;
        if(time[0]=='?')
        { 
            if(time[1]=='?') ans+='1';
            else if(time[1]=='0'||time[1]=='1')
            {
                ans+='1';
            } 
            else ans+='0';
        }
        else ans+=time[0];

        if(time[1]=='?')
        {
            if(ans[0]=='1') ans+='1';
            else ans+='9';
        } 
        else ans+=time[1];

        ans+=':';

        if(time[3]=='?')
        {
            ans+='5';
        }
        else ans+=time[3];

        if(time[4]=='?')
        {
            ans+='9';
        }
        else ans+=time[4];

        return ans;
    }

};