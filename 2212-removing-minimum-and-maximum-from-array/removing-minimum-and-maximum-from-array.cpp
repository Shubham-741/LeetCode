class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int min_ele = INT_MAX;
        int min_idx = -1;
        int max_ele = INT_MIN;
        int max_idx = -1;

        for(int i = 0; i<n; i++){
            if(nums[i]<min_ele){
                min_ele = nums[i];
                min_idx = i;
            }

            if(nums[i]>max_ele){
                max_ele = nums[i];
                max_idx = i;
            }
        }

        // case 1 both from front;

        int ans1 = max(max_idx, min_idx)+1;

        // case2 remove both from back;

        int ans2 = n-min(max_idx,min_idx);


        // case2 = remove one from front and one from back;

        int f = min(max_idx, min_idx)+1;

        int b = n-max(max_idx, min_idx);

        int ans3 = f+b;

        int ans = min(ans3, min(ans1, ans2));

        return ans;
        
    }
};