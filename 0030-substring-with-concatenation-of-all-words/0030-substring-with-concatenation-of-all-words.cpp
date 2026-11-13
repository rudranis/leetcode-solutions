
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int n = s.size();
        int wordLen = words[0].size();
        int wordCount = words.size();

        int totalLen = wordLen * wordCount;

        if(n < totalLen) return ans;

        unordered_map<string, int> mp;

        for(string &word : words) {
            mp[word]++;
        }

        for(int i = 0; i < wordLen; i++) {

            int left = i;
            int right = i;
            int count = 0;

            unordered_map<string, int> seen;

            while(right + wordLen <= n) {

                string word = s.substr(right, wordLen);

                right += wordLen;

                if(mp.find(word) == mp.end()) {

                    seen.clear();
                    count = 0;
                    left = right;

                } 
                else {

                    seen[word]++;
                    count++;

                    while(seen[word] > mp[word]) {

                        string leftWord = s.substr(left, wordLen);

                        seen[leftWord]--;
                        count--;

                        left += wordLen;
                    }

                    if(count == wordCount) {

                        ans.push_back(left);

                        string leftWord = s.substr(left, wordLen);

                        seen[leftWord]--;
                        count--;

                        left += wordLen;
                    }
                }
            }
        }

        return ans;
    }
};
