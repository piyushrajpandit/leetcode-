/*
========================================
HOUSE ROBBER PROBLEM - DP APPROACHES
========================================

Problem:
Given an array nums where each element represents money in a house,
find the maximum money that can be robbed without robbing
two adjacent houses.

----------------------------------------
1. RECURSION
----------------------------------------
Idea:
For every house, we have 2 choices:
1. Include current house -> move to i-2
2. Exclude current house -> move to i-1

Recurrence:
f(i) = max(
            nums[i] + f(i-2),
            f(i-1)
          )

Base Cases:
f(i < 0) = 0
f(0) = nums[0]

Time Complexity  : O(2^n)
Space Complexity : O(n) recursion stack

----------------------------------------
2. RECURSION + MEMOIZATION (Top Down DP)
----------------------------------------
Idea:
Store already computed states in dp array
to avoid repeated recursive calls.

dp[i] stores maximum robbery amount till index i.

Time Complexity  : O(n)
Space Complexity : O(n) + O(n recursion stack)

----------------------------------------
3. TABULATION (Bottom Up DP)
----------------------------------------
Idea:
Build answer iteratively from smaller states.

Transition:
dp[i] = max(
              nums[i] + dp[i-2],
              dp[i-1]
            )

Initialization:
dp[0] = nums[0]

Time Complexity  : O(n)
Space Complexity : O(n)

----------------------------------------
4. SPACE OPTIMIZATION
----------------------------------------
Observation:
Current state only depends on previous two states.

prev1 -> dp[i-1]
prev2 -> dp[i-2]

Thus array can be replaced with 2 variables.

Time Complexity  : O(n)
Space Complexity : O(1)

----------------------------------------
OVERALL DP FLOW
----------------------------------------
Recursion
   ↓
Memoization
   ↓
Tabulation
   ↓
Space Optimization

Most Optimized Solution:
Time  : O(n)
Space : O(1)

*/

class Solution {
public:
    int solveTab(vector<int> &nums){
        int n= nums.size();
        int prev2= 0;
        int prev1= nums[0];
      
      

        for(int i =1; i<n;i++){
            int incl= prev2 + nums[i];
            int excl = prev1 ;

            int ans = max(incl , excl);
            prev2 = prev1;
            prev1 = ans;
           

        }
        return prev1;

    }
    int rob(vector<int>& nums) {
        return solveTab(nums);
    }
};

class Solution {
public:
    int solveTab(vector<int> &nums){
        int n= nums.size();
        vector<int> dp(n,0);

        dp[0]= nums[0];

        for(int i =1; i<n;i++){
            int incl= nums[i];
            if(i>1)
            incl+= dp[i-2];
            int excl = dp[i-1] + 0;
            dp[i] = max(incl, excl);

        }
        return dp[n-1];

    }
    int rob(vector<int>& nums) {
        return solveTab(nums);
    }
};

class Solution {
public:
    int solveMem(vector<int> &nums, int n, vector<int>& dp){
        //base case 
        if(n<0){
            return 0;

        }
        if(n==0){
            return nums[0];
        }
        if(dp[n]!= -1){
            return dp[n];
        }
        int incl = solveMem(nums,n-2,dp)+ nums[n];
        int exel = solveMem(nums,n-1,dp) + 0;
        dp[n] = max(incl, exel);
        return dp[n];

    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,-1);
        
        return solveMem(nums, n-1, dp);
    }
};


class Solution {
public:
    int solve(vector<int> &nums, int n){
        //base case 
        if(n<0){
            return 0;

        }
        if(n==0){
            return nums[0];
        }
        int incl = solve(nums,n-2)+ nums[n];
        int exel = solve(nums,n-1) + 0;
        return max(incl, exel);

    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        int ans = solve(nums,n-1);
        return ans;
    }
};
