class Solution {
public:

    long long findgcd(long long a, long long b){
        if (b == 0){
            return a;
        }

        return findgcd(b, a % b);
    }

    long long findlcm(long long a, long long b){
        return (a / findgcd(a, b)) * b;
    }

    int maxLength(vector<int>& nums) {

        int n = nums.size();

        int ans = 0;

        for(int i = 0; i<n; i++){

            __int128 p = 1;
            long long g = nums[i];
            long long l = nums[i];

            for(int j = i; j<n; j++){

                if(p > (((__int128)1 << 126) / nums[j])) {
                    break;
                }

                p *= nums[j];

                g = findgcd(g, nums[j]);
                l = findlcm(l, nums[j]);

                if(p == (__int128)g * l){
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};