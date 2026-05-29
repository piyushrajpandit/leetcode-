/*
==========================================================
Minimum Score Triangulation of Polygon
(LeetCode 1039)

Problem:
Given a convex polygon where each vertex
has a value.

Divide polygon into triangles such that:
total triangulation score is minimum.

Triangle Score:
values[i] * values[j] * values[k]

Final Answer:
sum of all triangle scores.

----------------------------------------------------------
Core Idea:

Fix two vertices:
i and j

Try every possible middle vertex:
k

Form triangle:
(i, k, j)

Then recursively solve:
- left polygon  -> (i to k)
- right polygon -> (k to j)

----------------------------------------------------------
Recurrence Relation:

dp[i][j] =
min(
    values[i] * values[k] * values[j]
    + dp[i][k]
    + dp[k][j]
)

----------------------------------------------------------
DP Meaning:

dp[i][j] =
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

For every k:
- form triangle
- recursively solve left and right parts

Time Complexity:
Exponential

Space Complexity:
O(n) recursion stack

----------------------------------------------------------
2. Memoization (Top-Down DP)

Idea:
Store already computed states in dp[][].

Avoid repeated recursive calculations.

Time Complexity:
O(n^3)

Space Complexity:
O(n^2)

----------------------------------------------------------
3. Tabulation (Bottom-Up DP)

Idea:
Build dp table diagonally.

Start from smaller polygon ranges
and move toward larger ranges.

Transition:
dp[i][j] =
minimum over all possible k.

Time Complexity:
O(n^3)

Space Complexity:
O(n^2)

----------------------------------------------------------
Why j starts from i+2 ?

Because:
At least 3 vertices are needed
to form one triangle.

----------------------------------------------------------
Learning Flow:

Recursion
-> brute force partitioning

Memoization
-> cache overlapping subproblems

Tabulation
-> iterative interval DP

----------------------------------------------------------
Pattern Recognition:

Whenever you see:
- partitioning intervals
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
    int solve(vector<int>& v, int i, int j){
        //base case 
        if(i+1 == j){
            return 0;
        }
        int ans = INT_MAX;
        for(int k = i+1; k<j; k++){
            ans = min(ans, v[i]*v[j]*v[k]+ solve(v, i ,k)+ solve(v,k,j));

        }
        return ans; 
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return solve(values, 0 ,n-1);
    }
};

class Solution {
public:
    int solve(vector<int>& v, int i, int j,vector<vector<int>> &dp){
        //base case 
        if(i+1 == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i+1; k<j; k++){
            ans = min(ans, v[i]*v[j]*v[k]+ solve(v, i ,k,dp)+ solve(v,k,j,dp));

        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(values, 0, n-1, dp);
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
