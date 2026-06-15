/*
LeetCode 1155: Number of Dice Rolls With Target Sum

Approaches:

1. Pure Recursion
-----------------
State:
    solve(dice, faces, target)
    = Number of ways to get 'target' using 'dice' dice.

Base Cases:
    target < 0                     -> 0
    dice == 0 && target == 0       -> 1
    dice == 0 && target != 0       -> 0
    dice != 0 && target == 0       -> 0

Transition:
    solve(dice, target)
    = Σ solve(dice-1, target-i)
      for i = 1 to faces

Time Complexity:
    O(faces^dice)

Space Complexity:
    O(dice)    // recursion stack


2. Memoization (Top-Down DP)
----------------------------
DP State:
    dp[dice][target]
    = Number of ways to get 'target' using 'dice' dice.

Transition:
    dp[dice][target]
    = Σ solve(dice-1, target-i)

Memoization avoids recomputation.

Time Complexity:
    O(dice × target × faces)

Space Complexity:
    O(dice × target) + O(dice)


3. Tabulation (Bottom-Up DP)
----------------------------
DP Definition:
    dp[d][t]
    = Number of ways to obtain sum 't'
      using exactly 'd' dice.

Base Case:
    dp[0][0] = 1

Transition:
    dp[d][target]
    += dp[d-1][target-i]
    for i = 1 to faces

Answer:
    dp[dice][target]

Time Complexity:
    O(dice × target × faces)

Space Complexity:
    O(dice × target)


4. Space Optimization
---------------------
Observation:
    Current row depends only on previous row.

Use:
    prev[target]
    curr[target]

Transition:
    curr[target]
    += prev[target-i]

After each dice:
    prev = curr

Answer:
    prev[target]

Time Complexity:
    O(dice × target × faces)

Space Complexity:
    O(target)


MOD:
    Since the number of ways can be very large,
    use MOD = 1e9 + 7.

Evolution:
    Recursion
        ↓
    Memoization
        ↓
    Tabulation
        ↓
    Space Optimization
*/


class Solution {
public:
    int solve(int dice, int faces, int target){
        //base case 
        if(target<0)
            return 0;
        if(dice == 0 && target != 0){
            return 0;
        }
        if(target == 0 && dice != 0)
            return 0;
        if(dice ==0 && target==0)
            return 1; 
        int ans =0 ;
        for(int i =1; i<= faces; i++){
            ans = ans + solve(dice-1, faces , target-i);
        }
        return ans; 
    }
    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target);
    }
};

class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int dice, int faces, int target, vector<vector<int>> &dp){
        //base case 
        if(target<0)
            return 0;
        if(dice == 0 && target != 0){
            return 0;
        }
        if(target == 0 && dice != 0)
            return 0;
        if(dice ==0 && target==0)
            return 1; 
        if(dp[dice][target] != -1)
            return dp[dice][target];
        long long ans =0 ;
        for(int i =1; i<= faces && i <= target; i++){
            ans = (ans + solve(dice-1, faces , target-i,dp))%MOD;
        }
        return dp[dice][target] = ans; 
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(n, k, target, dp);
    }
};


class Solution {
public:
    int solve(int d, int faces, int t){
        //base case 
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(d+1, vector<int>(t+1, 0));
        dp[0][0] = 1;
        for(int dice =1; dice <=d;dice++){
            for(int target =1; target <= t; target++){
                long long ans =0 ;
                for(int i =1; i<=faces; i++){
                    if(target -i >= 0)
                    ans = (ans + dp[dice -1][target-i])%MOD;
                }
                 dp[dice][target] = ans;

            }
        }
      return dp[d][t];
    }
    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target);
    }
};

class Solution {
public:
    int solve(int d, int faces, int t){
        //base case 
        int MOD = 1e9 + 7;
        vector<int> prev  (t+1,0);
        vector<int> curr (t+1, 0);

        prev[0] = 1;
        for(int dice =1; dice <=d;dice++){
            for(int target =1; target <= t; target++){
                long long ans =0 ;
                for(int i =1; i<=faces; i++){
                    if(target -i >= 0)
                    ans = (ans + prev[target-i])%MOD;
                }
                 curr[target] = ans;

            }
            prev= curr;
        }
      return prev[t];
    }
    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target);
    }
};
