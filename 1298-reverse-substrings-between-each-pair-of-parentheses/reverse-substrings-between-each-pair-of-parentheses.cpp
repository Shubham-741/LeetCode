class Solution {
public:
    string reverseParentheses(string s) {

        stack<int>lastlengthtoskip;

        string result = "";

        for(char &ch : s){
            if (ch == '('){
                lastlengthtoskip.push(result.size());
            }
            else if (ch == ')'){
                int l = lastlengthtoskip.top();
                reverse(result.begin()+l, result.end());
                lastlengthtoskip.pop();
            }
            else{
                result.push_back(ch);
            }
        }

        return result;
        
    }
};