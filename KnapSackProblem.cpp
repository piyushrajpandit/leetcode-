/*
==========================================================
0/1 Knapsack Problem

Problem:
Given:
- weight[]  -> weights of items
- value[]   -> values of items
- capacity  -> maximum capacity of knapsack

Find:
Maximum total value that can be carried.

Condition:
Each item can be picked only once.

----------------------------------------------------------
Recurrence Relation:

For every item:
1. Include item
2. Exclude item

dp[index][capacity] =
max(include, exclude)

----------------------------------------------------------
1. Recursive Approach

Idea:
For every item:
- either include it
- or exclude it

Time Complexity:
O(2^n)

Space Complexity:
O(n)

Drawback:
Repeated subproblems.

----------------------------------------------------------
2. Memoization (Top-Down DP)

Idea:
Store already computed states in dp[][]

State:
dp[index][capacity]

Time Complexity:
O(n * capacity)

Space Complexity:
O(n * capacity)

----------------------------------------------------------
3. Tabulation (Bottom-Up DP)

Idea:
Build answers iteratively using dp table.

Transition:
include =
value[index] +
dp[index-1][capacity-weight[index]]

exclude =
dp[index-1][capacity]

Time Complexity:
O(n * capacity)

Space Complexity:
O(n * capacity)

----------------------------------------------------------
4. Space Optimized DP

Idea:
Only previous row is needed.

Use:
- prev[]
- curr[]

Time Complexity:
O(n * capacity)

Space Complexity:
O(capacity)

----------------------------------------------------------
Learning Flow:

Recursion
-> brute force exploration

Memoization
-> avoid repeated recursion

Tabulation
-> iterative DP

Space Optimization
-> reduce memory usage

==========================================================
*/



// ======================================================
// 1. Recursive Solution
// ======================================================

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& weight,
          vector<int>& value,
          int index,
          int capacity) {

    // base case
    if(index == 0) {

        if(weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    int include = 0;

    if(weight[index] <= capacity)
        include =
            value[index] +
            solve(weight,
                  value,
                  index - 1,
                  capacity - weight[index]);

    int exclude =
        solve(weight,
              value,
              index - 1,
              capacity);

    int ans = max(include, exclude);

    return ans;
}

int knapsack(vector<int> weight,
             vector<int> value,
             int n,
             int maxWeight) {

    return solve(weight,
                 value,
                 n - 1,
                 maxWeight);
}




// ======================================================
// 2. Memoization (Top-Down DP)
// ======================================================

#include <bits/stdc++.h>
using namespace std;

int solveMem(vector<int>& weight,
             vector<int>& value,
             int index,
             int capacity,
             vector<vector<int>>& dp) {

    // base case
    if(index == 0) {

        if(weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    // already solved
    if(dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;

    if(weight[index] <= capacity)
        include =
            value[index] +
            solveMem(weight,
                     value,
                     index - 1,
                     capacity - weight[index],
                     dp);

    int exclude =
        solveMem(weight,
                 value,
                 index - 1,
                 capacity,
                 dp);

    dp[index][capacity] =
        max(include, exclude);

    return dp[index][capacity];
}

int knapsack(vector<int> weight,
             vector<int> value,
             int n,
             int maxWeight) {

    vector<vector<int>> dp(
        n,
        vector<int>(maxWeight + 1, -1));

    return solveMem(weight,
                    value,
                    n - 1,
                    maxWeight,
                    dp);
}




// ======================================================
// 3. Tabulation (Bottom-Up DP)
// ======================================================

#include <bits/stdc++.h>
using namespace std;

int solveTab(vector<int>& weight,
             vector<int>& value,
             int n,
             int capacity) {

    // step 1
    vector<vector<int>> dp(
        n,
        vector<int>(capacity + 1, 0));

    // step 2 : base case
    for(int w = weight[0];
        w <= capacity;
        w++) {

        dp[0][w] = value[0];
    }

    // step 3
    for(int index = 1;
        index < n;
        index++) {

        for(int w = 0;
            w <= capacity;
            w++) {

            int include = 0;

            if(weight[index] <= w)
                include =
                    value[index] +
                    dp[index - 1]
                      [w - weight[index]];

            int exclude =
                dp[index - 1][w];

            dp[index][w] =
                max(include, exclude);
        }
    }

    return dp[n - 1][capacity];
}

int knapsack(vector<int> weight,
             vector<int> value,
             int n,
             int maxWeight) {

    return solveTab(weight,
                    value,
                    n,
                    maxWeight);
}




// ======================================================
// 4. Space Optimized DP
// ======================================================

#include <bits/stdc++.h>
using namespace std;

int solveSO(vector<int>& weight,
            vector<int>& value,
            int n,
            int capacity) {

    vector<int> prev(capacity + 1, 0);

    vector<int> curr(capacity + 1, 0);

    // base case
    for(int w = weight[0];
        w <= capacity;
        w++) {

        prev[w] = value[0];
    }

    // remaining calls
    for(int index = 1;
        index < n;
        index++) {

        for(int w = 0;
            w <= capacity;
            w++) {

            int include = 0;

            if(weight[index] <= w)
                include =
                    value[index] +
                    prev[w - weight[index]];

            int exclude =
                prev[w];

            curr[w] =
                max(include, exclude);
        }

        prev = curr;
    }

    return prev[capacity];
}

int knapsack(vector<int> weight,
             vector<int> value,
             int n,
             int maxWeight) {

    return solveSO(weight,
                   value,
                   n,
                   maxWeight);
}
