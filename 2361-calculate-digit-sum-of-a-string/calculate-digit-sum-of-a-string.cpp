class Solution {
public:
    string digitSum(string s, int k) {

        int n = s.size();

        while(n>k){
            string x = "";
            for(int i = 0; i<n; i+=k){

                string sub = s.substr(i,k);

                int sum = 0;

                for(char ch : sub){
                    sum += ch - '0';
                }

                x += to_string(sum);

                
            }

            s = x;

            n = x.size();
        }

        return s;
        
    }
};