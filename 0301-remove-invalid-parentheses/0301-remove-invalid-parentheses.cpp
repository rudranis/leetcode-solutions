class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;

    void solve(string& s, int index, int leftremove, int rightremove,
               int balance, string curr) {

        if (balance < 0)
            return;

        if (index == s.size()) {

            if (balance == 0 && leftremove == 0 && rightremove == 0) {

                st.insert(curr);
            }

            return;
        }

        char c = s[index];

        // '('
        if (c == '(') {

            // Remove '('
            if (leftremove > 0) {
                solve(s, index + 1, leftremove - 1, rightremove, balance, curr);
            }

            // Keep '('
            solve(s, index + 1, leftremove, rightremove, balance + 1, curr + c);
        }

        // ')'
        else if (c == ')') {

            // Remove ')'
            if (rightremove > 0) {
                solve(s, index + 1, leftremove, rightremove - 1, balance, curr);
            }

            // Keep ')' only if '(' exists
            if (balance > 0) {
                solve(s, index + 1, leftremove, rightremove, balance - 1,
                      curr + c);
            }
        }

        // Letter
        else {
            solve(s, index + 1, leftremove, rightremove, balance, curr + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals
        for (char c : s) {

            if (c == '(') {
                leftRemove++;
            } else if (c == ')') {

                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }

        solve(s, 0, leftRemove, rightRemove, 0, "");

        for (string x : st)
            ans.push_back(x);

        return ans;
    }
};