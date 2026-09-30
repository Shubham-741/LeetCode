class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        int n = seq.size();
        vector<int> ans(n);

        int d = 0;  // Current nesting depth

        for (int i = 0; i < n; i++) {

            if (seq[i] == '(') {

                d++;  // Enter a deeper level

                // Alternate groups based on depth:
                // Odd depth  -> group 1
                // Even depth -> group 0
                //
                // This splits the nesting depth roughly in half.
                if (d % 2 == 0) {
                    ans[i] = 0;
                } else {
                    ans[i] = 1;
                }

            } else {

                // For ')', use the depth BEFORE decreasing it.
                // This ensures the closing bracket goes into the
                // same group as its corresponding opening bracket.
                if (d % 2 == 0) {
                    ans[i] = 0;
                } else {
                    ans[i] = 1;
                }

                d--;  // Exit the current nesting level
            }
        }

        return ans;
    }
};