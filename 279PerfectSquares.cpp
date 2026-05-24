/*
==========================================================
Perfect Squares Problem (LeetCode 279)

Problem:
Given an integer n,
return the minimum number of perfect square
numbers whose sum equals n.

Perfect Squares:
1, 4, 9, 16, 25, ...

Example:
n = 12

12 = 4 + 4 + 4

Answer = 3

----------------------------------------------------------
Core Idea:

For every number:
try every perfect square <= current number.

Transition:

dp[i] =
min(dp[i], 1 + dp[i - perfectSquare])

Meaning:
- take one perfect square
- recursively/iteratively solve remaining value

----------------------------------------------------------
1. Recursive Approach

Idea:
Try every perfect square recursively.

At every step:
- subtract perfect square
- solve remaining number

Time Complexity:
Exponential

Space Complexity:
O(n) recursion stack

Drawback:
Repeated subproblems.

----------------------------------------------------------
2. Memoization (Top-Down DP)

Idea:
Store already computed answers in dp[].

DP Meaning:
dp[i] =
minimum perfect squares needed to form i

Time Complexity:
O(n * sqrt(n))

Space Complexity:
O(n)

----------------------------------------------------------
3. Tabulation (Bottom-Up DP)

Idea:
Build answer iteratively from 0 to n.

Transition:
dp[i] =
min(dp[i], 1 + dp[i - j*j])

Time Complexity:
O(n * sqrt(n))

Space Complexity:
O(n)

----------------------------------------------------------
Learning Flow:

Recursion
-> brute force exploration

Memoization
-> avoid repeated recursion

Tabulation
-> iterative DP solution

----------------------------------------------------------
Key Observation:

For every number i:
try all perfect squares:
1^2, 2^2, 3^2 ...

where:
j*j <= i

==========================================================
*/


class Solution {
public:
    int solve(int n){
         //base case 
        if(n==0)
            return 0;
        int ans = n;
        for(int i=1;i*i <=n;i++){
            int temp = i*i;
            ans = min(ans, 1+solve(n-temp));
        }
        return ans;
    }
    
    int numSquares(int n) {
       return solve(n);
    }
};


class Solution {
public:
    int solve(int n,vector<int> & dp){
         //base case 
        if(n==0)
            return 0;

        if(dp[n]!= -1)
            return dp[n];
        int ans = n;
        for(int i=1;i*i <=n;i++){
            int temp = i*i;
            ans = min(ans, 1+solve(n-temp,dp));
        }
        dp[n] = ans;
        return dp[n];
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solve(n,dp);
    }
};


class Solution {
public:
    int solve(int n){
         vector<int> dp(n+1, INT_MAX);
         dp[0] = 0;
         for(int i =1; i<= n ; i++){
            for(int j =1; j*j<= i;j++){
                int temp = j*j;
                if(i-temp>=0)
                dp[i] = min(dp[i],1+ dp[i- temp]);
            }
         }
        return dp[n];
    }
    
    int numSquares(int n) {
       
        return solve(n);
    }
};
