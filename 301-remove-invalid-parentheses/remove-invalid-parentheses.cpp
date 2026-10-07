class Solution {
public:

    int n;
    unordered_set<string>st;
    int maxLen;

    void solve(string&s, int i, string& curr,int count, int& maxLen){

        if(count<0){
            return;
        }

        if(i==n){
            if(count == 0){
                if(curr.length() > maxLen){
                    maxLen = curr.length();
                    st.clear();
                }

                if(curr.length() == maxLen){
                    st.insert(curr);
                }                
            }
            return;
        }

        if(s[i]!='(' && s[i]!=')'){
            curr.push_back(s[i]);
            solve(s, i+1, curr, count, maxLen);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);
        solve(s, i+1, curr, count + (s[i]=='(' ? 1 : -1), maxLen);

        //undo
        curr.pop_back();

        solve(s, i+1, curr, count, maxLen);

    }

    vector<string> removeInvalidParentheses(string s) {

        n = s.size();
        maxLen = 0;

        string curr = "";

        solve(s, 0, curr,0, maxLen);

        return vector<string>(st.begin(), st.end());

        
    }
};