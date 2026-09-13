class Solution {
public:

    int countOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int row_off, int col_off){
        int count = 0;

        for(int i = 0; i<img1.size(); i++){
            for(int j = 0; j<img2.size(); j++){
                int B_i = i+row_off;
                int B_j = j+col_off;

                if(B_i<0 || B_i>=img1.size() || B_j<0 || B_j>=img2.size()){
                    continue;
                }

                if(img1[i][j]==1 && img2[B_i][B_j]==1){
                    count++;
                }
            }
        }

        return count;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int m = img1.size();
        int n = img2.size();

        int ans = INT_MIN;

        for(int row_off = -m+1; row_off<m; row_off++){
            for(int col_off = -n+1; col_off<n; col_off++){
                int overlap = countOverlap(img1, img2, row_off, col_off);
                ans = max(ans, overlap);
            }
        }

        return ans;
        
    }
};