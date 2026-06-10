/*=========================================
Pizza With 3n Slices - DP Approaches
=========================================

1. Pure Recursion
-----------------
Approach:
- Since the pizza is circular, we cannot take both the first and last slice.
- Solve two linear cases:
  1. Consider slices from index 0 to k-2 (exclude last slice).
  2. Consider slices from index 1 to k-1 (exclude first slice).
- At every index:
  - Take the current slice and move to index + 2.
  - Skip the current slice and move to index + 1.
- Select exactly k/3 slices and return the maximum possible sum.

Time Complexity: O(2^N)
Space Complexity: O(N)  [Recursion Stack]


2. Recursion + Memoization
--------------------------
Approach:
- Use DP memoization to avoid recomputing overlapping subproblems.
- State:
    dp[index][n]
    = Maximum sum obtainable starting from 'index'
      while selecting 'n' more slices.
- For each state:
    take    = slices[index] + solve(index+2, n-1)
    notTake = solve(index+1, n)
- Handle circular nature by solving:
  1. Excluding the last slice.
  2. Excluding the first slice.
- Return the maximum of both cases.

Time Complexity: O(N * (N/3)) ≈ O(N²)
Space Complexity: O(N * (N/3)) + O(N)


3. Bottom-Up DP (Tabulation)
----------------------------
Approach:
- Convert the memoized solution into an iterative DP.
- State:
    dp[index][n]
    = Maximum sum obtainable starting from 'index'
      while selecting 'n' slices.
- Transition:
    take    = slices[index] + dp[index+2][n-1]
    notTake = dp[index+1][n]

    dp[index][n] = max(take, notTake)

- Compute states in reverse order.
- Solve two cases:
  1. Exclude last slice.
  2. Exclude first slice.
- Return the maximum answer.

Time Complexity: O(N * (N/3)) ≈ O(N²)
Space Complexity: O(N * (N/3))


4. Space Optimized DP
---------------------
Approach:
- Observe that each DP state depends only on:
    dp[index+1]
    dp[index+2]
- Therefore, instead of storing the entire DP table,
  maintain only three 1D arrays:
    prev -> current row being computed
    curr -> dp[index+1]
    next -> dp[index+2]
- Update arrays while iterating backwards.
- Solve:
  1. Excluding the last slice.
  2. Excluding the first slice.
- Return the maximum of both results.

Time Complexity: O(N * (N/3)) ≈ O(N²)
Space Complexity: O(N)


Key DP Transition
-----------------
take    = slices[index] + DP(index + 2, n - 1)
notTake = DP(index + 1, n)

answer  = max(take, notTake)

Circular Array Handling
-----------------------
Case 1: Use slices[0 ... k-2]  (Exclude last slice)
Case 2: Use slices[1 ... k-1]  (Exclude first slice)

Final Answer:
max(case1, case2)

*/
class Solution {
public:
    int solve(int index,int endIndex,  vector<int>& slices, int n){
        //base case 
        if(n==0|| index>endIndex){
            return 0;
        }
        int take = slices[index] + solve(index+2,endIndex,  slices , n-1);
        int notTake = 0 + solve(index+1 ,endIndex, slices ,n);
        return max(take , notTake);
        
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        int case1 = solve(0,k-2,slices, k/3);
        int case2 = solve(1,k-1, slices, k/3);
        return max(case1, case2);
    }
};


class Solution {
public:
    int solve(int index,int endIndex,  vector<int>& slices, int n,vector<vector<int>> &dp){
        //base case 
        if(n==0|| index>endIndex){
            return 0;
        }
        if(dp[index][n] != -1)
            return dp[index][n];
        int take = slices[index] + solve(index+2,endIndex,  slices , n-1,dp);
        int notTake = 0 + solve(index+1 ,endIndex, slices ,n,dp);
        return dp[index][n] =  max(take , notTake);
        
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp(k, vector<int>(k, -1));
        int case1 = solve(0,k-2,slices, k/3,dp);

        vector<vector<int>> dp2(k, vector<int>(k, -1));
        int case2 = solve(1,k-1, slices, k/3,dp2);
        return max(case1, case2);
    }
};

class Solution {
public:
    int solve( vector<int>& slices){
         int k = slices.size();
        vector<vector<int>> dp(k+2, vector<int>(k+2, 0));
        

        vector<vector<int>> dp2(k+2, vector<int>(k+2, 0));
       


       for(int index = k-2 ; index >= 0; index--){
        for(int n =1; n<= k/3;n++){
            int take = slices[index] + dp[index+2][n-1];
            int notTake = 0 + dp[index+1][n];

            dp[index][n] = max(take , notTake);
        }
       }
    int case1 = dp[0][k/3];
       

       for(int index = k-1; index >= 1; index--){
        for(int n =1; n<= k/3;n++){
            int take = slices[index] + dp2[index+2][n-1];
            int notTake = 0 + dp2[index+1][n];

            dp2[index][n] = max(take , notTake);
        }
       }
    int case2 = dp2[1][k/3];

    return max(case1, case2);
       
        
    }
    int maxSizeSlices(vector<int>& slices) {
       
        return solve(slices);
    }
};

class Solution {
public:
    int solve( vector<int>& slices){
         int k = slices.size();
  
        vector<int> prev1(k+2, 0);
        vector<int> curr1(k+2, 0);
        vector<int> next1(k+2, 0);
        vector<int> prev2(k+2, 0);
        vector<int> curr2(k+2, 0);
        vector<int> next2(k+2, 0);
        

       


       for(int index = k-2 ; index >= 0; index--){
        for(int n =1; n<= k/3;n++){
            int take = slices[index] + next1[n-1];
            int notTake = 0 + curr1[n];

           prev1[n] = max(take , notTake);
        }
        next1 = curr1;
        curr1 = prev1;
       }
    int case1 = curr1[k/3];
       

       for(int index = k-1; index >= 1; index--){
        for(int n =1; n<= k/3;n++){
            int take = slices[index] + next2[n-1];
            int notTake = 0 + curr2[n];

            prev2[n] = max(take , notTake);
        }
        next2 = curr2;
        curr2 = prev2;
       }
    int case2 = curr2[k/3];

    return max(case1, case2);
       
        
    }
    int maxSizeSlices(vector<int>& slices) {
       
        return solve(slices);
    }
};
