class Solution {
public:

    const int MOD = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {

        int n = arr.size();
        int prefix = 0;
        int oddSum = 0;
        int evenSum = 1;

        int ans = 0;

        for(int i = 0; i<n; i++){
            prefix += arr[i];

            if(prefix %2 != 0){
                ans = (ans + evenSum)%MOD;
                oddSum++;
            }

            else{
                ans = (ans + oddSum)%MOD;
                evenSum++;
            }
        }

        return ans;
        
    }
};