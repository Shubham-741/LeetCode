class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n = nums.size();

        int x = 1;
        int y = 1;

        int i = 0;

        for(int j = 1; j<n; j++){
            if(nums[j]<=nums[j-1]){
                i=j;
            }
            x = max(x, j-i+1);
        }

        i = 0;

        for(int j = 1;j<n; j++){
            if(nums[j]>=nums[j-1]){
                i=j;
            }
            y = max(y, j-i+1);
        }

        int ans = max(x,y);

        return ans;
        
    }
};