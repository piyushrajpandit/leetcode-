/*
==========================================================
Minimum Sideway Jumps
(LeetCode 1824)

Problem:
A frog starts at:
- lane 2
- position 0

There are:
- 3 lanes
- obstacles in some lanes

Goal:
Reach the end using minimum side jumps.

----------------------------------------------------------
Core Idea:

At every position:
1. Move forward if next cell is free
2. Otherwise perform side jump

Forward movement costs:
0

Side jump costs:
1

----------------------------------------------------------
State Definition:

dp[lane][pos]

=
minimum side jumps needed
from current lane and position.

----------------------------------------------------------
Base Case:

If:
pos == n

Reached destination.

Return:
0

----------------------------------------------------------
1. Recursive Solution

Idea:
- If next position is free:
  move forward

- Otherwise:
  try side jumps to all valid lanes

Time Complexity:
Exponential

Reason:
same states solved repeatedly.

Space Complexity:
O(n)
(recursion stack)

----------------------------------------------------------
2. Tabulation (Bottom-Up DP)

Idea:
Build DP table from back to front.

Transition:

If next cell is free:
dp[lane][pos] =
dp[lane][pos+1]

Else:
Try all possible side jumps.

Take minimum.

Time Complexity:
O(n)

Space Complexity:
O(4*n)

----------------------------------------------------------
3. Space Optimized DP

Observation:
Current state only depends on:
next position.

So instead of full DP table:
use only:
- curr[4]
- next[4]

Space reduced from:
O(4*n)
to:
O(1)

Time Complexity:
O(n)

Space Complexity:
O(1)

----------------------------------------------------------
Important Insight:

The frog prefers:
forward movement

because:
forward move cost = 0

Side jump only happens
when obstacle blocks path.

----------------------------------------------------------
Pattern Recognition:

This is a Dynamic Programming problem involving:
- states
- transitions
- minimum operations

Very similar to:
- grid DP
- path optimization
- lane switching problems

==========================================================



==========================================================
Minimum Score Triangulation of Polygon
(LeetCode 1039)

Problem:
Given a convex polygon where each vertex
contains a value.

Divide polygon into triangles such that:
total triangulation score is minimum.

Triangle Score:
values[i] * values[j] * values[k]

Final answer:
sum of all triangle scores.

----------------------------------------------------------
Core Idea:

Fix two vertices:
i and j

Try every possible partition point:
k

Form triangle:
(i, k, j)

Then recursively solve:
- left polygon
- right polygon

----------------------------------------------------------
Recurrence Relation:

dp[i][j] =
min(
    values[i] * values[k] * values[j]
    + dp[i][k]
    + dp[k][j]
)

----------------------------------------------------------
State Meaning:

dp[i][j]

=
minimum triangulation cost
between vertices i and j.

----------------------------------------------------------
Base Case:

If:
i + 1 == j

No triangle possible.

Return:
0

----------------------------------------------------------
1. Recursive Solution

Idea:
Try every possible partition point k.

Recursively solve:
- left part
- right part

Take minimum answer.

Time Complexity:
Exponential

Space Complexity:
O(n)
(recursion stack)

----------------------------------------------------------
2. Tabulation (Bottom-Up DP)

Idea:
Build DP table diagonally.

Start from smaller intervals
and move toward larger intervals.

Transition:
Try every possible partition point k.

Time Complexity:
O(n^3)

Space Complexity:
O(n^2)

----------------------------------------------------------
Why j starts from i+2 ?

Because:
At least 3 vertices are required
to form one triangle.

----------------------------------------------------------
Pattern Recognition:

Whenever you see:
- interval partitioning
- choosing split point
- minimizing cost

Think:
Interval Dynamic Programming

Similar Problems:
- Matrix Chain Multiplication
- Burst Balloons
- Palindrome Partitioning

==========================================================
*/

class Solution {
public:
    int solve(vector<int>& obstacles, int currlane, int pos){
        //base case 
        int n= obstacles.size()-1;
        if(pos==n){
            return 0;

        }
        if(obstacles[pos+1] != currlane){
            return solve(obstacles, currlane, pos+1);
        }
        else{
            //sideways jump
            int ans= INT_MAX;
            for(int i =1; i<=3; i++){
                if(currlane != i && obstacles[pos]!= i)
                    ans = min(ans, 1 + solve(obstacles, i, pos));
            }
            return ans;
        }
    }
    int minSideJumps(vector<int>& obstacles) {

        return solve(obstacles, 2, 0);

    }
};



class Solution {
public:
    int solve(vector<int>& v){
        int n = v.size();
         vector<vector<int>> dp(n, vector<int>(n,0));


         for(int i=n-1; i>=0 ; i--){
            for(int j= i+2; j<n; j++){
                
        int ans = INT_MAX;
        for(int k = i+1; k<j; k++){
            ans = min(ans, v[i]*v[j]*v[k]+ dp[i][k]+ dp[k][j]);

        }
        dp[i][j] = ans;
      
            }
         }
       return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        
        
       
        return solve(values);
    }
};


class Solution {
public:

    int solve(vector<int>& obstacles) {

        int n = obstacles.size() - 1;

        vector<vector<int>> dp(
            4,
            vector<int>(n + 1, INT_MAX)
        );

        // base case
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int pos = n - 1; pos >= 0; pos--) {

            for(int lane = 1; lane <= 3; lane++) {

                // forward move possible
                if(obstacles[pos + 1] != lane) {

                    dp[lane][pos] =
                        dp[lane][pos + 1];
                }

                else {

                    int ans = INT_MAX;

                    // side jumps
                    for(int i = 1; i <= 3; i++) {

                        if(lane != i &&
                           obstacles[pos] != i) {

                            ans = min(
                                    ans,
                                    1 + dp[i][pos + 1]
                                  );
                        }
                    }

                    dp[lane][pos] = ans;
                }
            }
        }

        return min(
                    dp[2][0],
                    min(
                        1 + dp[1][0],
                        1 + dp[3][0]
                    )
               );
    }

    int minSideJumps(vector<int>& obstacles) {

        return solve(obstacles);
    }
};

class Solution {
public:

    int solve(vector<int>& obstacles) {

        int n = obstacles.size() - 1;

        vector<int> curr(4, INT_MAX);
        vector<int> next(4,INT_MAX);

        // base case
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int pos = n - 1; pos >= 0; pos--) {

            for(int lane = 1; lane <= 3; lane++) {

                // forward move possible
                if(obstacles[pos + 1] != lane) {

                    curr[lane]=
                        next[lane];
                }

                else {

                    int ans = INT_MAX;

                    // side jumps
                    for(int i = 1; i <= 3; i++) {

                        if(lane != i &&
                           obstacles[pos] != i) {

                            ans = min(
                                    ans,
                                    1 + next[i]
                                  );
                        }
                    }

                    curr[lane]= ans;
                }
            }
            next = curr;
        }

        return min(
                next[2],
                    min(
                        1 + next[1],
                        1 + next[3]
                    )
               );
    }

    int minSideJumps(vector<int>& obstacles) {

        return solve(obstacles);
    }
};
