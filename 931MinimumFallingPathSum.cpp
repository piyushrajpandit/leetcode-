class Solution {
public:
    int solve(vector<vector<int>>& matrix ,int i , int j,int row, int col){

        if(i == row -1 ){
            return matrix[i][j];
        }

        int temp1 = INT_MAX;
        int temp2 = INT_MAX;
        int temp3 = INT_MAX;
        //case one just down 
        if(i +1 < row){
            temp1 = matrix[i][j] + solve(matrix , i+1, j, row, col);
        }
        //left diagonal 
        if(j-1 >=0 && i +1 < row){
            temp2 = matrix[i][j] +  solve(matrix, i+1, j-1, row , col);
        }
        //right diagonal 
        if(j+ 1 < col && i+1 < row){
            temp3 = matrix[i][j] + solve(matrix, i+1, j+1, row , col );
        }
        return min({temp1, temp2, temp3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col = matrix[0].size();
        int answer = INT_MAX;

        for(int i =0 ; i< col; i++){
            int temp = solve(matrix, 0, i,row, col);
            answer = min(answer, temp);
        }
        return answer;
    }
};



class Solution {
public:
    int solve(vector<vector<int>>& matrix ,int i , int j,int row, int col,vector<vector<int>>& dp){

        if(i == row -1 ){
            return matrix[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int temp1 = INT_MAX;
        int temp2 = INT_MAX;
        int temp3 = INT_MAX;
        //case one just down 
        if(i +1 < row){
            temp1 = matrix[i][j] + solve(matrix , i+1, j, row, col,dp);
        }
        //left diagonal 
        if(j-1 >=0 && i +1 < row){
            temp2 = matrix[i][j] +  solve(matrix, i+1, j-1, row , col,dp);
        }
        //right diagonal 
        if(j+ 1 < col && i+1 < row){
            temp3 = matrix[i][j] + solve(matrix, i+1, j+1, row , col,dp );
        }
        return dp[i][j] = min({temp1, temp2, temp3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col = matrix[0].size();
        int answer = INT_MAX;
        vector<vector<int>> dp(row, vector<int>(col, -1));
        for(int i =0 ; i< col; i++){
            int temp = solve(matrix, 0, i,row, col,dp);
            answer = min(answer, temp);
        }
        return answer;
    }
};

class Solution {
public:
    int solve(vector<vector<int>>& matrix ,int i , int j,int row, int col,vector<vector<int>>& dp,vector<vector<bool>>& visited){

        if(i == row -1 ){
            return matrix[i][j];
        }
        if(visited[i][j]){
            return dp[i][j];
        }
        visited[i][j] = true;
         int ans = INT_MAX;

        // Down
        ans = min(ans, matrix[i][j] +
                       solve(matrix, i + 1, j, row, col, dp, visited));

        // Left diagonal
        if(j - 1 >= 0) {
            ans = min(ans, matrix[i][j] +
                           solve(matrix, i + 1, j - 1, row, col, dp, visited));
        }

        // Right diagonal
        if(j + 1 < col) {
            ans = min(ans, matrix[i][j] +
                           solve(matrix, i + 1, j + 1, row, col, dp, visited));
        }

        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col = matrix[0].size();
        int answer = INT_MAX;
        vector<vector<int>> dp(row, vector<int>(col, -1));
        vector<vector<bool>> visited(row, vector<bool>(col , false));
        for(int i =0 ; i< col; i++){
            int temp = solve(matrix, 0, i,row, col,dp,visited);
            answer = min(answer, temp);
        }
        return answer;
    }
};
