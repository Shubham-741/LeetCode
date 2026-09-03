class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int n = nums1.size();

        int so = INT_MAX;
        int se = INT_MAX;

        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 0){
                se = min(se, nums1[i]);
            }
            else{
                so = min(so, nums1[i]);
            }
        }

        // to make all odd
        bool allodd = true;

        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 0){
                if(so == INT_MAX || nums1[i] - so < 1){
                    allodd = false;
                    break;
                }
            }
        }

        // to make all even
        bool alleven = true;

        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 1){
                if(so == INT_MAX || nums1[i] - so < 1){
                    alleven = false;
                    break;
                }
            }
        }

        return allodd || alleven;
    }
};