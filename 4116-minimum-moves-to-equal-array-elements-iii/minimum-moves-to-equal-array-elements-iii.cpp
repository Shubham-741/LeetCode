class Solution {
public:
    int minMoves(vector<int>& nums) {

        int ans = 0;

        int max_ele = *max_element(nums.begin(), nums.end());

        for(int x : nums){
            ans += (max_ele-x);
        }        

        return ans;
    }
};