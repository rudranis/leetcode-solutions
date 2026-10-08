class Solution {
public:
    bool match(string query, string pattern) {
        int i = 0;

        for (char c : query) {

            // Pattern character matched
            if (i < pattern.size() && c == pattern[i]) {
                i++;
            }

            // Extra uppercase character is not allowed
            else if (isupper(c)) {
                return false;
            }

            // Extra lowercase character → ignore
        }

        // All pattern characters must be matched
        return i == pattern.size();
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;

        for (string query : queries) {
            ans.push_back(match(query, pattern));
        }

        return ans;
    }
};