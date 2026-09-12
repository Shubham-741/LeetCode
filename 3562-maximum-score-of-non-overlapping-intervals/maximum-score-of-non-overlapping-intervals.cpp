class Solution {
public:
    int n;
    vector<int> nextIdx;

    struct Node {
        long long score = 0;
        vector<int> idxs;
    };

    vector<vector<Node>> t;
    vector<vector<bool>> vis;

    int findNext(vector<vector<int>>& intervals, int r) {
        int lo = 0, hi = n - 1;
        int result = n;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (intervals[mid][0] > r) {
                result = mid;
                hi = mid - 1;
            } 
            else {
                lo = mid + 1;
            }
        }

        return result;
    }

    Node solve(vector<vector<int>>& intervals, int i, int k) {

        // No more intervals or no selections left
        if (i >= n || k == 0)
            return Node{0, {}};

        // Already calculated
        if (vis[i][k])
            return t[i][k];

        vis[i][k] = true;

        int weight = intervals[i][2];
        int idx = intervals[i][3];

        int j = nextIdx[i];

        // Skip interval i
        Node skip = solve(intervals, i + 1, k);

        // Take interval i
        Node temp = solve(intervals, j, k - 1);

        Node take;

        take.score = temp.score + weight;
        take.idxs = temp.idxs;
        take.idxs.push_back(idx);

        // Sort original indices for lexicographical comparison
        sort(take.idxs.begin(), take.idxs.end());

        Node result;

        // Choose maximum score
        if (skip.score > take.score) {
            result = skip;
        }
        else if (skip.score < take.score) {
            result = take;
        }
        // Same score -> lexicographically smaller indices
        else {
            result = (skip.idxs < take.idxs) ? skip : take;
        }

        return t[i][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        // Store original index
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        // Sort by start, then end, then weight, then original index
        sort(intervals.begin(), intervals.end());

        // Find next non-overlapping interval
        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {
            int r = intervals[i][1];
            nextIdx[i] = findNext(intervals, r);
        }

        const int K = 4;

        // DP table
        t.assign(n + 1, vector<Node>(K + 1));

        // Visited table for memoization
        vis.assign(n + 1, vector<bool>(K + 1, false));

        return solve(intervals, 0, K).idxs;
    }
};