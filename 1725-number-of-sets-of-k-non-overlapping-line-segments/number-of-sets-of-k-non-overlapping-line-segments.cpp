class Solution {
public:

    static const int M = 1e9 + 7;

    int t[1001][1001];
    int sum[1001][1001];

    int solve(int n, int k, int i) {

        if(k == 0)
            return 1;

        if(i >= n)
            return 0;

        if(t[i][k] != -1)
            return t[i][k];

        // sum of:
        // solve(i+1,k-1) + solve(i+2,k-1) + ... + solve(n-1,k-1)

        long long take = getSum(n, k - 1, i + 1);

        long long skip = solve(n, k, i + 1);

        return t[i][k] = (take + skip) % M;
    }

    int getSum(int n, int k, int i) {

        if(i >= n)
            return 0;

        if(sum[i][k] != -1)
            return sum[i][k];

        return sum[i][k] =
            (solve(n, k, i) + getSum(n, k, i + 1)) % M;
    }

    int numberOfSets(int n, int k) {

        memset(t, -1, sizeof(t));
        memset(sum, -1, sizeof(sum));

        return solve(n, k, 0);
    }
};