/*
==========================================================
Count Derangements (LeetCode 634)

Definition:
A derangement is a permutation where no element
appears in its original position.

Example:
n = 3

Original:
1 2 3

Valid Derangements:
2 3 1
3 1 2

Answer = 2

----------------------------------------------------------
Recurrence Relation:

f(n) = (n-1) * (f(n-1) + f(n-2))

Explanation:
For the nth element:
- it cannot stay in its own position
- choose one of the remaining (n-1) positions

Two cases occur:
1. Direct swap
2. Indirect arrangement

Thus:
f(n) = (n-1) * (f(n-1) + f(n-2))

----------------------------------------------------------
Base Cases:

f(1) = 0
Only one element -> cannot derange

f(2) = 1
Only one valid arrangement:
2 1

----------------------------------------------------------
1. Recursive Approach

Idea:
Solve recursively using recurrence relation.

Time Complexity:
O(2^n)

Space Complexity:
O(n) recursion stack

Drawback:
Repeated subproblems cause exponential time.

----------------------------------------------------------
2. Memoization (Top-Down DP)

Idea:
Store already computed answers in dp[]
to avoid repeated calculations.

DP Meaning:
dp[i] = number of derangements for i elements

Time Complexity:
O(n)

Space Complexity:
O(n)

----------------------------------------------------------
3. Tabulation (Bottom-Up DP)

Idea:
Build answers iteratively from smaller values.

Transition:
dp[i] =
(i-1) * (dp[i-1] + dp[i-2])

Time Complexity:
O(n)

Space Complexity:
O(n)

----------------------------------------------------------
4. Space Optimized DP

Idea:
Since only previous two states are needed,
store only:
prev1 and prev2

Time Complexity:
O(n)

Space Complexity:
O(1)

----------------------------------------------------------
Learning Flow:

Recursion
-> understand recurrence

Memoization
-> avoid recomputation

Tabulation
-> iterative DP solution

Space Optimization
-> reduce memory usage

==========================================================
*/

/*
==========================================================
Count Derangements (LeetCode 634)

A Derangement means:
No element remains at its original position.

----------------------------------------------------------
Formula:

f(n) = (n-1) * (f(n-1) + f(n-2))

Base Cases:
f(1) = 0
f(2) = 1

----------------------------------------------------------
1. Recursive Approach

Time Complexity:
O(2^n)

Space Complexity:
O(n)

----------------------------------------------------------
2. Memoization (Top-Down DP)

Idea:
Store already computed answers in dp[]

Time Complexity:
O(n)

Space Complexity:
O(n)

----------------------------------------------------------
3. Tabulation (Bottom-Up DP)

Idea:
Build answers iteratively from smaller values.

Time Complexity:
O(n)

Space Complexity:
O(n)

----------------------------------------------------------
4. Space Optimized DP

Idea:
Use only previous two states.

Time Complexity:
O(n)

Space Complexity:
O(1)

==========================================================
*/


// ======================================================
// 1. Recursive Solution
// ======================================================

class Solution {
public:

    long long MOD = 1e9 + 7;

    long long countDerangements(int n) {

        // base case
        if(n == 1)
            return 0;

        if(n == 2)
            return 1;

        long long ans =
            ((n - 1) % MOD *
            ((countDerangements(n - 1) % MOD +
              countDerangements(n - 2) % MOD) % MOD))
            % MOD;

        return ans;
    }
};


// ======================================================
// 2. Memoization (Top-Down DP)
// ======================================================

class Solution {
public:

    long long MOD = 1e9 + 7;

    long long solveMem(int n,
                       vector<long long>& dp) {

        // base case
        if(n == 1)
            return 0;

        if(n == 2)
            return 1;

        // already computed
        if(dp[n] != -1)
            return dp[n];

        dp[n] =
            ((n - 1) % MOD *
            ((solveMem(n - 1, dp) % MOD +
              solveMem(n - 2, dp) % MOD) % MOD))
            % MOD;

        return dp[n];
    }

    long long countDerangements(int n) {

        vector<long long> dp(n + 1, -1);

        return solveMem(n, dp);
    }
};


// ======================================================
// 3. Tabulation (Bottom-Up DP)
// ======================================================

class Solution {
public:

    long long MOD = 1e9 + 7;

    long long solveTab(int n) {

        vector<long long> dp(n + 1, 0);

        // base case
        dp[1] = 0;
        dp[2] = 1;

        for(int i = 3; i <= n; i++) {

            long long first = dp[i - 1] % MOD;

            long long second = dp[i - 2] % MOD;

            long long sum =
                (first + second) % MOD;

            dp[i] =
                ((i - 1) * sum) % MOD;
        }

        return dp[n];
    }

    long long countDerangements(int n) {

        return solveTab(n);
    }
};


// ======================================================
// 4. Space Optimized DP
// ======================================================

class Solution {
public:

    long long MOD = 1e9 + 7;

    long long solveSO(int n) {

        // base case
        if(n == 1)
            return 0;

        if(n == 2)
            return 1;

        long long prev2 = 0;
        long long prev1 = 1;

        for(int i = 3; i <= n; i++) {

            long long first = prev1 % MOD;

            long long second = prev2 % MOD;

            long long sum =
                (first + second) % MOD;

            long long ans =
                ((i - 1) * sum) % MOD;

            prev2 = prev1;

            prev1 = ans;
        }

        return prev1;
    }

    long long countDerangements(int n) {

        return solveSO(n);
    }
};
