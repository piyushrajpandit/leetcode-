// time complexiry for recussion and learining x*n space o(n) 
// tabulation x* n o(n)

// ==========================================================
// Coin Change Problem (LeetCode 322)
//
// Goal:
// Find the minimum number of coins required
// to make the given amount.
//
// ----------------------------------------------------------
// 1. Recursive Approach
//
// Idea:
// Try every coin and recursively solve
// the remaining amount.
//
// Recurrence:
// f(x) = 1 + min(f(x - coin))
//
// Base Cases:
// x == 0  -> return 0
// x < 0   -> return INT_MAX
//
// Time Complexity:
// O(n^x)
//
// Space Complexity:
// O(x)
//
// Drawback:
// Repeated calculation of same subproblems.
// Can cause TLE for large inputs.
//
// ----------------------------------------------------------
// 2. Memoization (Top-Down DP)
//
// Idea:
// Store already computed answers in dp[]
// to avoid recalculating.
//
// DP Meaning:
// dp[x] = minimum coins needed for amount x
//
// Transition:
// dp[x] = min(dp[x], 1 + dp[x - coin])
//
// Time Complexity:
// O(x * n)
//
// Space Complexity:
// O(x)
//
// Advantage:
// Each amount solved only once.
//
// ----------------------------------------------------------
// 3. Tabulation (Bottom-Up DP)
//
// Idea:
// Build solutions iteratively from
// smaller amounts to larger amounts.
//
// Initialization:
// dp[0] = 0
//
// Transition:
// dp[i] = min(dp[i], 1 + dp[i - coin])
//
// Time Complexity:
// O(x * n)
//
// Space Complexity:
// O(x)
//
// Advantage:
// No recursion stack used.
//
// ----------------------------------------------------------
// Learning Flow:
//
// Recursion
//    -> understand brute force
//
// Memoization
//    -> avoid repeated calculations
//
// Tabulation
//    -> iterative dynamic programming
//
// ==========================================================

class Solution {
public:
    int solveTab(vector<int> &num, int x){
        vector<int> dp(x+1, INT_MAX);
        dp[0] = 0;
        for(int i =1; i<= x; i++){
            //i m trying to solve for every amount figure from 1 to x
            
            for(int j =0; j<num.size();j++){
                if(i - num[j] >= 0 && dp[i-num[j]]!= INT_MAX){
                    dp[i] = min(dp[i], 1 + dp[i- num[j]]);
                }
            }
        }
        if(dp[x]== INT_MAX)
            return -1 ;
        return dp[x];
    }
    int coinChange(vector<int>& coins, int amount) {
        return solveTab(coins,amount);
    }
};


class Solution {
public:
    int solveRec(vector<int> &num, int x, vector<int>& dp){
        //base case 
        if(x==0 ){
            return 0 ;

        }
        if(x< 0)
            return INT_MAX;
        
        if(dp[x]!= -1){
            return dp[x];
        }
        int mini = INT_MAX;
        for(int i=0; i< num.size();i++){
            int ans = solveRec(num, x-num[i],dp);
            if(ans != INT_MAX)
                mini = min(mini, 1+ans);
        }
        dp[x] = mini;

        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = solveRec(coins, amount,dp);

        
        if(ans == INT_MAX){
            return -1;
        }
        else
        return ans;
    }
};




class Solution {
public:
    int solveRec(vector<int> &num, int x){
        //base case 
        if(x==0 ){
            return 0 ;

        }
        if(x< 0)
            return INT_MAX;
        int mini = INT_MAX;
        for(int i=0; i< num.size();i++){
            int ans = solveRec(num, x-num[i]);
            if(ans != INT_MAX)
                mini = min(mini, 1+ans);
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solveRec(coins, amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
