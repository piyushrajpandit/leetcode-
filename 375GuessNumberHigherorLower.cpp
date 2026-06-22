/*
LeetCode 375: Guess Number Higher or Lower II

Idea:
- We need the minimum amount of money required to guarantee a win.
- For every range [start, end], try every number i as the first guess.
- If i is chosen, worst-case cost =
      i + max(cost of left range, cost of right range)
  because after paying i, the answer could lie in either side and
  we must be prepared for the more expensive (worst-case) scenario.
- Take the minimum cost among all possible first guesses.

Approaches:

1. Pure Recursion
   solve(start, end)
   - Recursively try every guess i in [start, end].
   - Base Case: start >= end => 0 (only one or no number left).
   - Time: Exponential
   - Space: O(n) recursion stack

2. Recursion + Memoization (Top-Down DP)
   - Store results of ranges [start][end] in dp.
   - Avoid recomputation of overlapping subproblems.
   - Time: O(n^3)
   - Space: O(n^2) + recursion stack

3. Bottom-Up DP (Tabulation)
   - dp[start][end] stores minimum guaranteed cost for range [start, end].
   - Fill smaller ranges first by iterating start from n to 1.
   - Transition:
       dp[start][end] =
       min over i in [start, end]
       { i + max(dp[start][i-1], dp[i+1][end]) }
   - Time: O(n^3)
   - Space: O(n^2)

Key Observation:
Choose the guess that minimizes the worst-case cost, since we need
a strategy that guarantees finding the number regardless of where it lies.
*/

class Solution {
public:
    int solve(int start, int end){
        if(start >= end)
            return 0;
        int maxi = INT_MAX;
        for(int i = start; i<= end; i++){
            maxi = min(maxi , i+max(solve(start, i-1),solve(i+1, end)));

        }
        return maxi;
    }
    int getMoneyAmount(int n) {
        return solve(1,n);
    }
};

class Solution {
public:
    int solve(int start, int end,vector<vector<int>> &dp){
        if(start >= end)
            return 0;
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int maxi = INT_MAX;
        for(int i = start; i<= end; i++){
            maxi = min(maxi , i+max(solve(start, i-1,dp),solve(i+1, end,dp)));

        }
        return dp[start][end]=  maxi;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1,n,dp);
    }
};

class Solution {
public:
    int solve(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int start = n; start >=1; start--){
            for(int end = start ; end <= n; end++){
                if(start == end )
                    continue;
                else
                {
                int maxi = INT_MAX;
                for(int i = start; i<= end; i++){
                     maxi = min(maxi , i+max(dp[start][i-1],dp[i+1][end]));

                 }
                 dp[start][end]=  maxi;

                }
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
        
        return solve(n);
    }
};
