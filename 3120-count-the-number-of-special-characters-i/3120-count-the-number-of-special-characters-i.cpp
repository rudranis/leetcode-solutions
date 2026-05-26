class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>upper,lower;
        for(char ch:word){
            if(islower(ch))
                lower.insert(ch);
            else
                upper.insert(ch);

        }
        int count=0;
        for(char c='a';c<='z';c++){
            if(lower.count(c) && upper.count(toupper(c)))
                count++;
        }
        return count;
    }
};