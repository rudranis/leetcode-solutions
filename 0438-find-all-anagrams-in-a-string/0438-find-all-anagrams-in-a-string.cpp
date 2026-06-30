class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
         int n = s.size();
        int m = p.size();

        vector<int> ans;

        if (m > n)
            return ans;

        vector<int> f1(26, 0), f2(26, 0);

        for (char ch : p)
            f1[ch - 'a']++;
        for (int i = 0; i < m; i++)
            f2[s[i] - 'a']++;

        if (f1 == f2)
            ans.push_back(0);
        for (int i = m; i < n; i++) {

            f2[s[i] - 'a']++;         // Add new character

            f2[s[i - m] - 'a']--;     // Remove old character

            if (f1 == f2)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};