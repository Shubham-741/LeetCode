
class Solution {
public:

    int n;
    vector<vector<int>> dp;

    int find(vector<int>& nums, int i, int target) {

        int idx = lower_bound(nums.begin()+i, nums.end(), target)-nums.begin();

        if(idx < n && nums[idx] == target) {
            return idx;
        }

        return -1;
    }

    int solve(int i, int inc, vector<int>& nums) {

        if(dp[i][inc] != -1) {
            return dp[i][inc];
        }

        int curr = nums[i] + inc;

        int l = 1;

        int j = find(nums, i+1, curr+1);

        if(j != -1) {
            l = max(l, 1 + solve(j, 0, nums));
        }

        j = find(nums, i+1, curr);

        if(j != -1) {
            l = max(l, 1 + solve(j, 1, nums));
        }

        return dp[i][inc] = l;
    }

    int maxSelectedElements(vector<int>& nums) {

        n = nums.size();

        sort(nums.begin(), nums.end());

        dp.assign(n, vector<int>(2, -1));

        int len = 1;

        for(int i = 0; i < n; i++) {
            len = max({len, solve(i, 0, nums), solve(i, 1, nums)});
        }

        return len;
    }
};
