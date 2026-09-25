class Solution {
public:

    // Parse an expression until we reach ',' or '}'
    set<string> parseExpression(string &s, int &i) {

        set<string> result = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> cur;

            if (s[i] == '{') {
                // Parse inside braces
                i++; 
                cur = parseUnion(s, i);
                i++; // skip '}'
            }
            else {
                // Single character
                cur.insert(string(1, s[i]));
                i++;
            }

            // Concatenate result × cur
            set<string> temp;

            for (const string &a : result) {
                for (const string &b : cur) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }


    // Parse comma-separated expressions
    set<string> parseUnion(string &s, int &i) {

        set<string> result = parseExpression(s, i);

        while (i < s.size() && s[i] == ',') {
            i++; // skip ','

            set<string> next = parseExpression(s, i);

            result.insert(next.begin(), next.end());
        }

        return result;
    }


    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parseUnion(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};