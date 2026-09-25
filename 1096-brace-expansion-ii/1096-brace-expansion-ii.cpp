class Solution {
public:

    set<string> solve(string &s, int &i) {

        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            // UNION
            if (s[i] == ',') {

                for (string x : current) {
                    result.insert(x);
                }

                current.clear();
                current.insert("");

                i++;
            }

            // CONCATENATION
            else {

                set<string> next = parseChunk(s, i);

                set<string> temp;

                for (string a : current) {
                    for (string b : next) {
                        temp.insert(a + b);
                    }
                }

                current = temp;
            }
        }

        // Add last part
        for (string x : current) {
            result.insert(x);
        }

        return result;
    }


    set<string> parseChunk(string &s, int &i) {

        // Letter
        if (islower(s[i])) {

            string x(1, s[i]);
            i++;

            return {x};
        }

        // Braces
        i++; // skip {

        set<string> ans = solve(s, i);

        i++; // skip }

        return ans;
    }


    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};