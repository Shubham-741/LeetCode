class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int idx = n/2;

        int median = nums[idx];

        int ans = 0;

        for(int x : nums){
            ans += (abs(x-median));
        }

        return ans;
        
    }
};