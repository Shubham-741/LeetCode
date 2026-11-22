class Solution {
public:
    bool checkString(string s) {

        int n = s.size();

        int lastA = INT_MAX;
        int firstB = INT_MIN;

        for(int i = n-1; i>=0; i--){
            if (s[i]=='a'){
                lastA = i;
                break;
            }
        }

        for(int i = 0; i<n; i++){
            if(s[i]=='b'){
                firstB = i;
                break;
            }
        }

        if (lastA == INT_MAX || firstB == INT_MIN){
            return true;
        }

        return lastA < firstB;
        
    }
};