class Solution {
public:
    bool isPalindromic(string s) {
          string binary;

        for (char c : s) {
            bitset<8> b(c);
            binary += b.to_string();
        }

        string rev = binary;
        reverse(rev.begin(), rev.end());

        return binary == rev;
    }
};