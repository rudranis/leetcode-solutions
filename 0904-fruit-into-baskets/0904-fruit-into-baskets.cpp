class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>freq;
        int l=0,maxlen=0;
        for(int r=0;r<fruits.size();r++){
            freq[fruits[r]]++;
            while(freq.size()>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0){
                    freq.erase(fruits[l]);
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};