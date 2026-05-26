/*
==========================================================
Maximal Square Problem (LeetCode 221)

Problem:
Given a binary matrix containing:
'0' and '1'

Find:
Largest square containing only 1's
and return its AREA.

----------------------------------------------------------
Core DP Idea:

For every cell:
if current cell is '1',

then:

current square size =
1 + minimum(
        right,
        diagonal,
        down
    )

Because:
a square can grow only if all
3 neighboring directions can support it.

----------------------------------------------------------
Transition:

dp[i][j] =
1 + min(right, diagonal, down)

----------------------------------------------------------
DP Meaning:

dp[i][j] =
largest square SIDE LENGTH
starting from cell (i, j)

Final Answer:
maxi * maxi

because problem asks AREA.

----------------------------------------------------------
1. Recursive Solution

Idea:
Recursively explore:
- right
- diagonal
- down

from every cell.

Time Complexity:
Exponential

Space Complexity:
O(n + m) recursion stack

Drawback:
Repeated recursive calls.

----------------------------------------------------------
2. Memoization (Top-Down DP)

Idea:
Store already computed states in dp[][].

Avoid repeated calculations.

Time Complexity:
O(n * m)

Space Complexity:
O(n * m)

----------------------------------------------------------
3. Tabulation (Bottom-Up DP)

Idea:
Build dp table from bottom-right
towards top-left.

Extra row and column added to
avoid boundary checks.

Transition:
dp[i][j] =
1 + min(
        dp[i][j+1],
        dp[i+1][j],
        dp[i+1][j+1]
    )

Time Complexity:
O(n * m)

Space Complexity:
O(n * m)

----------------------------------------------------------
4. Space Optimized DP

Idea:
Instead of full dp matrix,
store only:
- current row
- next row

Because:
current state depends only on:
- current row
- next row

Time Complexity:
O(n * m)

Space Complexity:
O(m)

----------------------------------------------------------
Learning Flow:

Recursion
-> brute force

Memoization
-> caching repeated states

Tabulation
-> iterative DP

Space Optimization
-> reduce memory usage

==========================================================
*/


class Solution {
public:
    int solve(vector<vector<char>> &mat, int i , int j , int &maxi){
        if(i >= mat.size() || j>= mat[0].size())
            return 0;
        int right = solve(mat , i , j+1,maxi);
        int diagnol = solve(mat, i+1, j+1,maxi);
        int down = solve(mat, i+1, j,maxi);

        if(mat[i][j]=='1'){
            int ans = 1+ min(right, min(diagnol , down));
            maxi = max(maxi , ans);
            return ans;
        }
        else{
            return 0;

        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi =0 ;
        solve(matrix, 0,0,maxi);
        return maxi* maxi ;
    }
};



class Solution {
public:
    int solve(vector<vector<char>> &mat, int i , int j ,vector<vector<int>> &dp, int &maxi){
        if(i >= mat.size() || j>= mat[0].size())
            return 0;

        if(dp[i][j]!= -1)
            return dp[i][j];
        int right = solve(mat , i , j+1,dp,maxi);
        int diagnol = solve(mat, i+1, j+1,dp,maxi);
        int down = solve(mat, i+1, j,dp,maxi);

        if(mat[i][j]=='1'){
            dp[i][j] = 1+ min(right, min(diagnol , down));
            maxi = max(maxi ,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j] = 0;

        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi =0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        solve(matrix, 0,0,dp,maxi);
        return maxi* maxi ;
    }
};




class Solution {
public:
    int solve(vector<vector<char>> &mat, int &maxi){
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row+1, vector<int> (col+1 , 0));
        for(int i = row -1 ; i >= 0 ; i--){
            for(int j = col-1; j>= 0 ; j--){
                int right = dp[i][j+1];
                int diagnol = dp[i+1][j+1];
                int down = dp[i+1][j];

                if(mat[i][j]=='1'){
                    dp[i][j] = 1+ min(right, min(diagnol , down));
                    maxi = max(maxi ,dp[i][j]);
                   
                }
                else{
                    dp[i][j] = 0;

                }
            }
        }
    return dp[0][0];
       
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi =0;
       
        solve(matrix, maxi);
        return maxi* maxi ;
    }
};



class Solution {
public:
    int solve(vector<vector<char>> &mat, int &maxi){
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> curr(col+1, 0);
        vector<int> next(col+1, 0);
        for(int i = row -1 ; i >= 0 ; i--){
            for(int j = col-1; j>= 0 ; j--){
                int right = curr[j+1];
                int diagnol = next[j+1];
                int down = next[j];

                if(mat[i][j]=='1'){
                   curr[j] = 1+ min(right, min(diagnol , down));
                    maxi = max(maxi ,curr[j]);
                   
                }
                else{
                    curr[j] = 0;

                }
            }
            next = curr ;

        }
    return next[0];
       
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi =0;
       
        solve(matrix, maxi);
        return maxi* maxi ;
    }
};
