
class Solution {
public:

    const long long MOD1 = 1e9 + 7;
    const long long MOD2 = 1e9 + 9;
    const long long BASE = 911382323;

    bool check(vector<int>& nums, int k) {

        int n = nums.size();

        long long power1 = 1;
        long long power2 = 1;

        // Calculate BASE^(k-1)
        for (int i = 1; i < k; i++) {

            power1 = (power1 * BASE) % MOD1;
            power2 = (power2 * BASE) % MOD2;
        }

        long long hash1 = 0;
        long long hash2 = 0;

        // Calculate hash of first window
        for (int i = 0; i < k; i++) {

            hash1 = (hash1 * BASE + nums[i]) % MOD1;
            hash2 = (hash2 * BASE + nums[i]) % MOD2;
        }

        unordered_map<long long, int> mp;

        // Store combined double hash
        long long key = hash1 * MOD2 + hash2;
        mp[key]++;

        // Calculate remaining window hashes
        for (int i = k; i < n; i++) {

            long long outgoing = nums[i-k];
            long long incoming = nums[i];

            hash1 = (hash1 - outgoing * power1 % MOD1 + MOD1) % MOD1;
            hash2 = (hash2 - outgoing * power2 % MOD2 + MOD2) % MOD2;

            hash1 = (hash1 * BASE + incoming) % MOD1;
            hash2 = (hash2 * BASE + incoming) % MOD2;

            key = hash1 * MOD2 + hash2;

            mp[key]++;
        }

        // Check if any subarray occurs exactly once
        for (auto it : mp) {

            if (it.second == 1) {
                return true;
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        int low = 1;
        int high = n;

        int ans = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(nums, mid)) {

                ans = mid;
                high = mid - 1;
            }
            else {

                low = mid + 1;
            }
        }

        return ans;
    }
};
