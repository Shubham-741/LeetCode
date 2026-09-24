class Solution {
public:

    int sumofdigits(int n){
        int sum = 0;
        while(n>0){
            int r = n%10;
            sum += r;
            n /= 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i<n; i++){
            int idx = i;
            if(sumofdigits(nums[i])==idx){
                return idx;
            }
        }

        return -1;
        
    }
};