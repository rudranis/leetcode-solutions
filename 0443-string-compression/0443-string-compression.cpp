class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0;
        int i=0;
        while(i<n){
            char curr_char=chars[i];
            int cnt=0;
            while(i<n && chars[i]==curr_char){
                cnt++;
                i++;
            }
            chars[index]=curr_char;
            index++;
            if(cnt>1){
                string count_str=to_string(cnt);// no la convert kela like 'a','2'
                for(char & ch:count_str){ 
                    chars[index]=ch; //writes the current single character into your main array at the index position.
                    index++;
                }
            }
        }
        return index;
    }
};