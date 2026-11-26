120. Triangle
class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j) {
        int row = triangle.size();

        if(i == row) {
            return 0;
        }

        int temp1 = solve(triangle, i+1, j);
        int temp2 = solve(triangle, i+1, j+1);

        return triangle[i][j] + min(temp1, temp2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle, 0, 0);
    }
};




class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j,
              vector<vector<int>>& dp) {

        int row = triangle.size();

        if(i == row) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int temp1 = solve(triangle, i+1, j, dp);
        int temp2 = solve(triangle, i+1, j+1, dp);

        return dp[i][j] = triangle[i][j] + min(temp1, temp2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();

        vector<vector<int>> dp(row, vector<int>(row, -1));

        return solve(triangle, 0, 0, dp);
    }
};
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1];
        for(int i = n -2 ; i>= 0 ; i--){
            for(int j =0; j <= i; j++){
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};
