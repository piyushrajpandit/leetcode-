class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        int count = 0;
        stack<tuple<int, int,int>> st;
        st.push({0,0,0});
        // 0 means right and 1 means down
        while(!st.empty()){
            auto [row, col , dir] = st.top();
            st.pop();
            if(row == m -1 && col == n-1){
                count = (count + 1)%MOD;
                continue;
            }
            if(grid[row][col] == 0){
                if(col + 1 < n){
                    st.push({row, col+ 1, 0});
                }
                if(row + 1 < m){
                    st.push({row + 1, col, 1});
                }
            }
            else{
                if(dir == 0 && row + 1 < m){
                    st.push({row + 1, col ,1});
                }
                else if(dir == 1 && col + 1 < n){
                    st.push({row, col+ 1, 0});
                }
            }

        }
        return count;
    }
};

// this is done by chat gpt so i am putting in revision folder
/*
LeetCode 3665: Twisted Mirror Path Count

Approach: Dynamic Programming (DP)

1. DP State:
   dp[i][j][0] = Number of ways to reach cell (i,j)
                 while moving RIGHT.

   dp[i][j][1] = Number of ways to reach cell (i,j)
                 while moving DOWN.

2. Why track direction?
   Mirrors behave differently depending on the direction
   from which we enter them.

3. Initialization:
   dp[0][0][0] = 1;
   We start at (0,0) with one possible path.

4. Traverse the grid:
   Use two nested loops to visit every cell.
   For each cell, process both incoming directions.

5. Movement Logic:

   If grid[i][j] == 0 (Normal Cell):
      - Move RIGHT -> (i, j+1)
      - Move DOWN  -> (i+1, j)

   If grid[i][j] == 1 (Mirror Cell):
      - If dir == 0 (RIGHT), redirect DOWN.
      - If dir == 1 (DOWN), redirect RIGHT.

6. Boundary Checks:
   Check row and column limits before updating DP
   to avoid accessing cells outside the grid.

7. DP Transition:
   Add the number of ways from the current state
   to the next state.

   dp[nextRow][nextCol][nextDir] =
       (dp[nextRow][nextCol][nextDir] + ways) % MOD;

8. Final Answer:
   Add both direction states at the destination:

   dp[m-1][n-1][0] + dp[m-1][n-1][1]

9. Modulo:
   Use MOD = 1e9 + 7 to prevent integer overflow.

10. Complexity:
    Time Complexity  = O(m * n)
    Space Complexity = O(m * n)

IMPORTANT:
Instead of exploring every possible path using DFS/Stack,
DP combines the number of paths reaching the same cell
with the same direction.

This avoids repeated calculations and fixes TLE.
*/
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        int count = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int>(2,0)));
        dp[0][0][0] = 1;
        
        for(int i =0 ; i< m ; i++){
            for(int j =0 ; j< n; j++){
                for(int dir = 0 ; dir < 2; dir++){
                    int ways = dp[i][j][dir];
                    if(ways == 0) continue;
                    if(grid[i][j] == 0){
                        if(j + 1 < n){
                            dp[i][j+1][0] = (dp[i][j+1][0] + ways) %MOD;
                        }
                        if(i + 1 < m){
                            dp[i+1][j][1] = (dp[i+1][j][1] + ways)
                            % MOD;
                        }
                    }
                    else{
                        if(dir == 0 && i+ 1 < m){
                            dp[i+1][j][1] = (dp[i+1][j][1] + ways) % MOD;
                        }
                        else if(dir == 1 && j+ 1 < n){
                            dp[i][j+1][0] = (dp[i][j+1][0] + ways) % MOD;
                        }
                    }
                }
            }
        }
        
        return (dp[m-1][n-1][0] + dp[m -1][n-1][1] ) % MOD;
    }
};
