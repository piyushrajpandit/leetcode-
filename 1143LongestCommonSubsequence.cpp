/*
==================== LONGEST COMMON SUBSEQUENCE (LCS) ====================

Problem:
Given two strings text1 and text2, return the length of their
Longest Common Subsequence.

Subsequence:
Characters appear in the same relative order but need not be contiguous.

---------------------------------------------------------------------------
1. RECURSIVE APPROACH (Brute Force)
---------------------------------------------------------------------------

State:
solve(i, j) = LCS length between
              a[i...n-1] and b[j...m-1].

Base Case:
If either string is exhausted, no characters can match.
    i == n || j == m  -> return 0

Transition:
1) Characters match:
       a[i] == b[j]
       ans = 1 + solve(i+1, j+1)

2) Characters don't match:
       Skip one character from either string.
       ans = max(
                solve(i+1, j),
                solve(i, j+1)
             )

Time Complexity : O(2^(n+m)) approximately
Space Complexity: O(n+m) recursion stack

---------------------------------------------------------------------------
2. MEMOIZATION (Top-Down DP)
---------------------------------------------------------------------------

Observation:
The same states (i, j) are solved repeatedly.

DP State:
dp[i][j] stores answer of solve(i, j).

Before solving:
if(dp[i][j] != -1)
    return dp[i][j];

Time Complexity : O(n*m)
Space Complexity: O(n*m) + recursion stack

---------------------------------------------------------------------------
3. TABULATION (Bottom-Up DP)
---------------------------------------------------------------------------

DP State:
dp[i][j] = LCS of suffixes
           a[i...n-1] and b[j...m-1]

Table Size:
(n+1) x (m+1)

Extra row and column:
Represent cases when one string is exhausted.

Why iterate backwards?
Because:
dp[i][j] depends on
    dp[i+1][j]
    dp[i][j+1]
    dp[i+1][j+1]

Transition:
Match:
    dp[i][j] = 1 + dp[i+1][j+1]

No Match:
    dp[i][j] = max(dp[i+1][j], dp[i][j+1])

Answer:
dp[0][0]

Time Complexity : O(n*m)
Space Complexity: O(n*m)

---------------------------------------------------------------------------
4. SPACE OPTIMIZATION
---------------------------------------------------------------------------

Observation:
Current row only depends on:
    - next row
    - current row's right cell

Therefore, instead of storing entire table,
store only two rows:

next -> dp[i+1][...]
curr -> dp[i][...]

Transition:
Match:
    curr[j] = 1 + next[j+1]

No Match:
    curr[j] = max(next[j], curr[j+1])

After processing one row:
    next = curr

Answer:
next[0]

Time Complexity : O(n*m)
Space Complexity: O(m)

---------------------------------------------------------------------------
LCS CHEAT SHEET
---------------------------------------------------------------------------

State      : dp[i][j] = answer from i and j onwards
Base Case  : if i==n or j==m -> 0
Match      : 1 + diagonal
No Match   : max(down, right)
Direction  : Bottom-right -> Top-left
Answer     : dp[0][0]
Optimization: 2D DP -> 2 rows -> 1 row (possible in some problems)

Key Formula:
if(a[i] == b[j])
    dp[i][j] = 1 + dp[i+1][j+1];
else
    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);

===========================================================================
*/

class Solution {
public:
    int solve(string& a , string& b, int i, int j){
           //base case 
           
        if(i == a.length())
            return 0;
        if(j == b.length())
            return 0;
        int ans = 0 ;
        if(a[i] ==b[j]){
            ans = 1 + solve(a,b,i+1, j+1);

        }
        else{
         ans = max(solve(a, b,i+1, j), solve(a, b,i, j+1));
        }
        return ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
     return solve(text1, text2, 0,0);
    }
};

class Solution {
public:
    int solve(string& a , string& b, int i, int j,vector<vector<int>>& dp){
           //base case 
           
        if(i == a.length())
            return 0;
        if(j == b.length())
            return 0;

        if(dp[i][j]!= -1)
            return dp[i][j];
        int ans = 0 ;
        if(a[i] ==b[j]){
            ans = 1 + solve(a,b,i+1, j+1,dp);

        }
        else{
         ans = max(solve(a, b,i+1, j,dp), solve(a, b,i, j+1,dp));
        }
        return dp[i][j] = ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
     return solve(text1, text2, 0,0,dp);
    }
};

class Solution {
public:
    int solve(string& a , string& b){
         vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));
        for(int i = a.length() -1 ; i >= 0; i--){
            for(int j= b.length() -1; j >= 0; j--){
                    int ans = 0 ;
                    if(a[i] ==b[j]){
                        ans = 1 + dp[i+1][j+1];
                     }
                    else{
                    ans = max(dp[i+1][j], dp[i][j+1]);
                    }
                     dp[i][j] = ans;
                        }
        }
    return dp[0][0];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
       
     return solve(text1, text2);
    }
};

class Solution {
public:
    int solve(string& a , string& b){
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int i = a.length() -1 ; i >= 0; i--){
            for(int j= b.length() -1; j >= 0; j--){
                    int ans = 0 ;
                    if(a[i] ==b[j]){
                        ans = 1 + next[j+1];
                     }
                    else{
                    ans = max(next[j], curr[j+1]);
                    }
                     curr[j] = ans;
                    }
                    next = curr;
        }
    return next[0];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
       
     return solve(text1, text2);
    }
};
