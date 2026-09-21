class Solution {
public:
    int k;
    vector<vector<long long>> dp;

    vector<long long> solve(int i, vector<int>& nums) {
        if (i < 0)
            return vector<long long>(k, 0);

        if (dp[i][0] != -1)
            return dp[i];

        vector<long long> cur(k, 0);

        // Subarray consisting only of nums[i]
        cur[nums[i] % k]++;

        // Extend subarrays ending at i-1
        vector<long long> prev = solve(i - 1, nums);

        for (int r = 0; r < k; r++) {
            int nr = (r * (nums[i] % k)) % k;
            cur[nr] += prev[r];
        }

        return dp[i] = cur;
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        this->k = k;

        int n = nums.size();

        dp.assign(n, vector<long long>(k, -1));

        vector<long long> result(k, 0);

        for (int i = 0; i < n; i++) {
            vector<long long> cur = solve(i, nums);

            for (int r = 0; r < k; r++)
                result[r] += cur[r];
        }

        return result;
    }
};