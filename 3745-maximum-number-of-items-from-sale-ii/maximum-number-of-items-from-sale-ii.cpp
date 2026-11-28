
class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        vector<int> freq(n + 1, 0);

        int mn = INT_MAX;

        // Find minimum price and frequency of factors
        for (auto &it : items) {
            freq[it[0]]++;
            mn = min(mn, it[1]);
        }

        // Calculate number of possible free copies
        vector<int> cnt(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }

            cnt[i]--;  // Exclude the item itself
        }

        // Sort items by price
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long remaining = budget;

        // Greedily purchase profitable bonus copies
        for (auto &it : items) {

            int factor = it[0];
            int price = it[1];

            // No benefit over buying normal copies
            if (2LL * mn <= price) {
                break;
            }

            long long take = min(
                (long long)cnt[factor],
                remaining / price
            );

            ans += 2LL * take;
            remaining -= take * price;
        }

        // Purchase normal copies with remaining budget
        ans += remaining / mn;

        return ans;
    }
};
