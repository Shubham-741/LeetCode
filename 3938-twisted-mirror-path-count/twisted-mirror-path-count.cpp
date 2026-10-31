class Solution {
public:

    int left = 1;
    int up = 0;
    int MOD = 1e9 + 7;
    int m,n;

    int dp[501][501][2];

    int solve(int i, int j, vector<vector<int>>&grid, int camefrom){
        if(i>=m || j>=n){
            return 0;
        }

        if(i==m-1 && j==n-1){
            return 1;
        }

        if(dp[i][j][camefrom]!=-1){
            return dp[i][j][camefrom];
        }

        if(grid[i][j]==1){
            if(camefrom == 1){
                return dp[i][j][camefrom] = solve(i+1,j,grid,up);
            }
            else{
                return dp[i][j][camefrom] = solve(i,j+1,grid,left);
            }
        }

        int total = 0;

        total = (total + solve(i,j+1,grid,left))%MOD;
        total = (total + solve(i+1,j,grid,up))%MOD;

        return dp[i][j][camefrom] = total;

    }

    int uniquePaths(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0,0,grid,left);
        
    }
};