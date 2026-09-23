class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();
        long long total = 0;

        // REVISION:
        // Avoid using 'x' as the loop variable because 'x'
        // is already a function parameter.
        for (int num : nums) {
            total += num;
        }

        // REVISION:
        // Instead of finding the elements to REMOVE,
        // find the longest subarray to KEEP.
        //
        // Sum of elements to keep = total - x
        long long target = total - x;

        // If target < 0, x is greater than the total sum,
        // so it is impossible to reduce x to exactly 0.
        if (target < 0) {
            return -1;
        }

        // REVISION:
        // target == 0 means x == total.
        // Therefore, we need to remove the entire array.
        if (target == 0) {
            return n;
        }

        int i = 0;
        long long curr = 0;
        int maxLen = -1;

        // Find the longest subarray whose sum is 'target'.
        // Since all nums[i] are positive, sliding window works.
        for (int j = 0; j < n; j++) {

            curr += nums[j];

            // If current window sum is too large,
            // shrink the window from the left.
            while (i <= j && curr > target) {
                curr -= nums[i];
                i++;
            }

            // Found a valid subarray.
            if (curr == target) {
                maxLen = max(maxLen, j - i + 1);
            }
        }

        // REVISION:
        // This check must be AFTER the complete loop.
        // Checking inside the loop could return -1
        // before finding a valid subarray later.
        if (maxLen == -1) {
            return -1;
        }

        // Keep the longest valid subarray.
        // Remove everything outside it.
        return n - maxLen;
    }
};