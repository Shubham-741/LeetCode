class Solution {
public:
    int minMoves(vector<int>& nums) {

        int n = nums.size();

        // Find the minimum element in the array
        int min_ele = *min_element(nums.begin(), nums.end());

        int ans = 0;

        // Incrementing n-1 elements is equivalent to
        // decrementing the remaining one element.
        // Therefore, we reduce every element to the minimum value.
        for(int x : nums) {

            // Number of moves required for this element
            // to become equal to the minimum element
            ans += (x - min_ele);
        }

        // Total minimum moves required
        return ans;
    }
};