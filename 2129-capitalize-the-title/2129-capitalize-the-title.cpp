class Solution {
public:
    string capitalizeTitle(string title) {
        for(int i=0;i<title.size();i++){
            title[i]=tolower(title[i]);
        }
        int start=0;
        for(int i=0;i<=title.size();i++){
            if(i==title.size() || title[i]==' '){
                int len=i-start;
                if(len>2){
                    title[start]=toupper(title[start]);
                }
                start=i+1;
            }
        }
        return title;
    }
};