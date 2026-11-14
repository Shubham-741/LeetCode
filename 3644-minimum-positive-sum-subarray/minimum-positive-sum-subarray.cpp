class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();
        vector<int>cumulative(n);

        cumulative[0]=nums[0];

        int ans = INT_MAX;

        for(int i = 1; i<n; i++){
            cumulative[i]=cumulative[i-1]+nums[i];
        }

        for(int i = 0; i<n; i++){
            for(int j = l; j<=r; j++){
                if( i+j-1 < n){

                    int s = cumulative[i+j-1];

                    if (i>0){
                        s-=cumulative[i-1];
                    }

                    if (s<=0){
                        continue;
                    }

                    ans = min(ans,s);

                }
            }
        }

        if (ans == INT_MAX){
            return -1;
        }

        return ans;

        return ans;
        
    }
};