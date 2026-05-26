/*
==========================================================
Minimum Cost For Tickets (LeetCode 983)

Problem:
Given:
- travel days[]
- ticket costs[]

Ticket Types:
1-day pass
7-day pass
30-day pass

Find:
Minimum cost required to travel on all given days.

----------------------------------------------------------
Core Idea:

For every travel day:
we have 3 choices:

1. Buy 1-day pass
2. Buy 7-day pass
3. Buy 30-day pass

Take minimum cost among all choices.

----------------------------------------------------------
Recurrence Relation:

dp[index] =
min(
    1-day pass cost,
    7-day pass cost,
    30-day pass cost
)

----------------------------------------------------------
1. Recursive Approach

Idea:
Try all 3 ticket options recursively.

For 7-day and 30-day pass:
skip all covered travel days.

Time Complexity:
Exponential

Space Complexity:
O(n)

----------------------------------------------------------
2. Memoization (Top-Down DP)

Idea:
Store already computed answers in dp[].

State:
dp[index] =
minimum cost from current travel day onward.

Time Complexity:
O(n)

Space Complexity:
O(n)

----------------------------------------------------------
3. Tabulation (Bottom-Up DP)

Idea:
Build answers from back to front.

Transition:
dp[k] =
minimum among:
- 1-day pass
- 7-day pass
- 30-day pass

Time Complexity:
O(n)

Space Complexity:
O(n)

----------------------------------------------------------
4. Queue Optimization

Idea:
Maintain active:
- weekly passes
- monthly passes

Queues store:
{start_day, total_cost}

Remove expired passes and choose minimum cost.

Time Complexity:
O(n)

Space Complexity:
O(n)

----------------------------------------------------------
Learning Flow:

Recursion
-> brute force exploration

Memoization
-> avoid repeated recursion

Tabulation
-> iterative DP

Queue Optimization
-> sliding window optimization

==========================================================
*/



// ======================================================
// 1. Queue Optimization Solution
// ======================================================

class Solution {
public:

    int mincostTickets(vector<int>& days,
                       vector<int>& costs) {

        int ans = 0;

        queue<pair<int, int>> month;
        queue<pair<int, int>> week;

        for(int day : days) {

            // remove expired passes

            while(!month.empty() &&
                  month.front().first + 30 <= day)
                month.pop();

            while(!week.empty() &&
                  week.front().first + 7 <= day)
                week.pop();

            // add new passes

            week.push(
                {day, ans + costs[1]});

            month.push(
                {day, ans + costs[2]});

            // minimum cost till current day

            ans = min(
                    ans + costs[0],
                    min(week.front().second,
                        month.front().second)
                  );
        }

        return ans;
    }
};



// ======================================================
// 2. Recursive Solution
// ======================================================

class Solution {
public:

    int solve(int n,
              vector<int>& days,
              vector<int>& cost,
              int index) {

        // base case
        if(index >= n)
            return 0;

        // 1-day pass
        int option1 =
            cost[0] +
            solve(n,
                  days,
                  cost,
                  index + 1);

        int i;

        // 7-day pass
        for(i = index;
            i < n &&
            days[i] < days[index] + 7;
            i++);

        int option2 =
            cost[1] +
            solve(n,
                  days,
                  cost,
                  i);

        // 30-day pass
        for(i = index;
            i < n &&
            days[i] < days[index] + 30;
            i++);

        int option3 =
            cost[2] +
            solve(n,
                  days,
                  cost,
                  i);

        return min(option1,
                   min(option2, option3));
    }

    int mincostTickets(vector<int>& days,
                       vector<int>& costs) {

        int n = days.size();

        return solve(n,
                     days,
                     costs,
                     0);
    }
};



// ======================================================
// 3. Memoization (Top-Down DP)
// ======================================================

class Solution {
public:

    int solveMem(int n,
                 vector<int>& days,
                 vector<int>& cost,
                 int index,
                 vector<int>& dp) {

        // base case
        if(index >= n)
            return 0;

        // already solved
        if(dp[index] != -1)
            return dp[index];

        // 1-day pass
        int option1 =
            cost[0] +
            solveMem(n,
                     days,
                     cost,
                     index + 1,
                     dp);

        int i;

        // 7-day pass
        for(i = index;
            i < n &&
            days[i] < days[index] + 7;
            i++);

        int option2 =
            cost[1] +
            solveMem(n,
                     days,
                     cost,
                     i,
                     dp);

        // 30-day pass
        for(i = index;
            i < n &&
            days[i] < days[index] + 30;
            i++);

        int option3 =
            cost[2] +
            solveMem(n,
                     days,
                     cost,
                     i,
                     dp);

        dp[index] =
            min(option1,
                min(option2, option3));

        return dp[index];
    }

    int mincostTickets(vector<int>& days,
                       vector<int>& costs) {

        int n = days.size();

        vector<int> dp(n + 1, -1);

        return solveMem(n,
                        days,
                        costs,
                        0,
                        dp);
    }
};



// ======================================================
// 4. Tabulation (Bottom-Up DP)
// ======================================================

class Solution {
public:

    int solveTab(int n,
                 vector<int>& days,
                 vector<int>& cost) {

        vector<int> dp(n + 1, 0);

        dp[n] = 0;

        for(int k = n - 1;
            k >= 0;
            k--) {

            // 1-day pass
            int option1 =
                cost[0] + dp[k + 1];

            int i;

            // 7-day pass
            for(i = k;
                i < n &&
                days[i] < days[k] + 7;
                i++);

            int option2 =
                cost[1] + dp[i];

            // 30-day pass
            for(i = k;
                i < n &&
                days[i] < days[k] + 30;
                i++);

            int option3 =
                cost[2] + dp[i];

            dp[k] =
                min(option1,
                    min(option2, option3));
        }

        return dp[0];
    }

    int mincostTickets(vector<int>& days,
                       vector<int>& costs) {

        int n = days.size();

        return solveTab(n,
                        days,
                        costs);
    }
};
