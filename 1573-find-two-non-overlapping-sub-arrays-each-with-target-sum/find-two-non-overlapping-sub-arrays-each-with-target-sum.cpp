class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        int i = 0;
        int ans = INT_MAX;
        int bestMinLen = INT_MAX;

        vector<int>bestTillIdx(n, INT_MAX);
        
        int sum = 0;

        for(int j = 0; j<n; j++){
            
            sum += arr[j];

            while(i<j && sum > target){
                sum -= arr[i];
                i++;
            }

            if(sum == target){
                int len = j-i+1;

                if (i>0 && bestTillIdx[i-1]!=INT_MAX){
                    ans = min(ans, bestTillIdx[i-1]+len);

                }

                bestMinLen = min(bestMinLen, len);

            }

            bestTillIdx[j] = bestMinLen;

        }

        if(ans == INT_MAX){
            return -1;
        }

        return ans;
        
    }
};