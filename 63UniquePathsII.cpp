class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int i , int j ){
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(i >= row || j>= col) return 0;
        if(obstacleGrid[i][j] ==1 ) return 0 ;
        if(i == row -1 && j == col-1 ) return 1;
        int right = 0;
        int left = 0;
         right = solve(obstacleGrid, i, j+1);
         left = solve(obstacleGrid, i+1, j);
        return left + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return solve(obstacleGrid, 0, 0 );
    }
};

class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int i , int j, vector<vector<int>>& dp ){
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(i >= row || j>= col) return 0;
        if(dp[i][j] != -1 ) return dp[i][j];
        if(obstacleGrid[i][j] ==1 ) return 0 ;
        if(i == row -1 && j == col-1 ) return 1;
        int right = 0;
        int left = 0;
         right = solve(obstacleGrid, i, j+1,dp);
         left = solve(obstacleGrid, i+1, j,dp);
        return dp[i][j] = left + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col , -1));
        return solve(obstacleGrid, 0, 0 ,dp);
    }
};
