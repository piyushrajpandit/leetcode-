// Paint Fence Problem - LeetCode 276
// ----------------------------------
// Given n fence posts and k colors,
// count the number of ways to paint the fence
// such that no more than 2 adjacent fences
// have the same color.
//
// Recurrence:
// ways(n) = (ways(n-1) + ways(n-2)) * (k-1)
//
// Time Complexity:
// Recursive      -> O(2^n)
// Memoization    -> O(n)
// Tabulation     -> O(n)
//
// Space Complexity:
// Recursive      -> O(n) recursion stack
// Memoization    -> O(n)
// Tabulation     -> O(n)

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

//--------------------------------------------------
// Helper Functions
//--------------------------------------------------

int add(int a, int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

int mul(int a, int b) {
    return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

//--------------------------------------------------
// 1. Recursive Solution
//--------------------------------------------------

int solve(int n, int k) {

    // Base Cases
    if (n == 1)
        return k;

    if (n == 2)
        return add(k, mul(k, k - 1));

    int ans = add(
        mul(solve(n - 2, k), k - 1),
        mul(solve(n - 1, k), k - 1)
    );

    return ans;
}

int numberOfWays(int n, int k) {
    return solve(n, k);
}

//--------------------------------------------------
// 2. Memoization Solution
//--------------------------------------------------

int solveMem(int n, int k, vector<int>& dp) {

    // Base Cases
    if (n == 1)
        return k;

    if (n == 2)
        return add(k, mul(k, k - 1));

    // Step-3: Check if already computed
    if (dp[n] != -1)
        return dp[n];

    // Step-2: Store and return
    dp[n] = add(
        mul(solveMem(n - 2, k, dp), k - 1),
        mul(solveMem(n - 1, k, dp), k - 1)
    );

    return dp[n];
}

int numberOfWaysMemo(int n, int k) {

    vector<int> dp(n + 1, -1);

    return solveMem(n, k, dp);
}

//--------------------------------------------------
// 3. Tabulation Solution
//--------------------------------------------------

int solveTab(int n, int k) {

    if (n == 1)
        return k;

    vector<int> dp(n + 1, 0);

    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++) {

        dp[i] = add(
            mul(dp[i - 2], k - 1),
            mul(dp[i - 1], k - 1)
        );
    }

    return dp[n];
}

int numberOfWaysTab(int n, int k) {
    return solveTab(n, k);
}


//

//

int solveTabSo(int n, int k ){
int prev2 = k; 
int prev1 = add(k, mul(k, k-1));

for(int i= 3 ; i<=n ; i++){
int ans = add(mul(prev2, k-1), mul(prev1, k-1));
prev2 = prev1;
prev1 = ans;
}
return prev1;
}
