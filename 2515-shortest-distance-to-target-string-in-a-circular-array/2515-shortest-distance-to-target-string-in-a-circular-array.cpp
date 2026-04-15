class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
       int n = words.size();
        int small = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
                int right = (i - startIndex + n) % n;
                int left  = (startIndex - i + n) % n;
                int diff = min(right, left);
                small = min(small, diff);
            }
        }
        return (small == INT_MAX) ? -1 : small;
    }
};