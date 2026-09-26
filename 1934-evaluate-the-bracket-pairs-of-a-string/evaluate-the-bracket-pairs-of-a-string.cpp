class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        int n = s.size();

        unordered_map<string, string> mp;

        for (vector<string>& st : knowledge) {
            string x = st[0];
            string y = st[1];
            mp[x] = y;
        }

        string ans = "";

        int i = 0;

        while (i < n) {

            if (s[i] == '(') {
                string res = "";
                i++;

                while (i < n && s[i] != ')') {
                    res += s[i];
                    i++;
                }

                if (mp.find(res) != mp.end()) {
                    ans += mp[res];
                }
                else {
                    ans += '?';
                }

            }
            
            else {
                ans += s[i];
            }

            i++;
        }

        return ans;
    }
};