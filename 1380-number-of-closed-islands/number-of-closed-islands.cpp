class Solution {
public:

    int m, n;

    bool dfs(vector<vector<int>>& grid, int i, int j){

        if(i<0 || j<0 || i>=m || j>=n){
            return false;
        }

        if(grid[i][j]==1){
            return true;
        }

        grid[i][j]=1;

        bool closed = true;

        if(!dfs(grid, i, j+1)){
            closed = false;
        }

        if(!dfs(grid, i+1, j)){
            closed = false;
        }

        if(!dfs(grid, i-1, j)){
            closed = false;
        }

        if(!dfs(grid, i, j-1)){
            closed = false;
        }

        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int ans = 0;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){

                if(grid[i][j] == 0 && dfs(grid, i, j)){
                    ans++;
                }

            }
        }

        return ans;
        
    }
};