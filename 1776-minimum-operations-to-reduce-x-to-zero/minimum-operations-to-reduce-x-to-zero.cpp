class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();
        long long total = 0;

        for (int x : nums) {
            total += x;
        }

        long long target = total - x;

        if (target < 0) {
            return -1;
        }

        if (target == 0) {
            return n;
        }

        int i = 0;
        long long curr = 0;
        int maxLen = -1;

        for (int j = 0; j < n; j++) {
            curr += nums[j];

            while (i <= j && curr > target) {
                curr -= nums[i];
                i++;
            }

            if (curr == target) {
                maxLen = max(maxLen, j - i + 1);
            }
        }

        if (maxLen == -1) {
            return -1;
        }

        return n - maxLen;
    }
};