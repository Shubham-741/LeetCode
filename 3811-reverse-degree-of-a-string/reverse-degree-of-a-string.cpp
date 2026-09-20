class Solution {
public:
    int reverseDegree(string s) {

        int ans = 0;

        int n = s.size();

        for(int i = 0; i<n; i++){
            int x = s[i]-'a';
            int p = 26-x;
            int s = p*(i+1);
            ans += s;
        }

        return ans;
        
    }
};