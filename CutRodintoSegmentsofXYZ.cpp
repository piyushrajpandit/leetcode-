// ==========================================================
// Cut Rod into Segments (x, y, z)
//
// Goal:
// Given a rod of length n and 3 possible cuts
// x, y, z:
//
// Find the maximum number of segments possible.
//
// ----------------------------------------------------------
// 1. Recursive Approach
//
// Idea:
// Try all three cuts recursively:
// - cut by x
// - cut by y
// - cut by z
//
// Recurrence:
// f(n) = 1 + max(
//              f(n-x),
//              f(n-y),
//              f(n-z)
//          )
//
// Base Cases:
// n == 0  -> return 0
// n < 0   -> return INT_MIN
//
// Time Complexity:
// Exponential
//
// Space Complexity:
// O(n) recursion stack
//
// Drawback:
// Same subproblems solved repeatedly.
//
// ----------------------------------------------------------
// 2. Memoization (Top-Down DP)
//
// Idea:
// Store already computed answers in dp[]
// to avoid repeated recursive calls.
//
// DP Meaning:
// dp[i] = maximum cuts possible for length i
//
// Transition:
// dp[n] = max(
//              solve(n-x)+1,
//              solve(n-y)+1,
//              solve(n-z)+1
//            )
//
// Time Complexity:
// O(n)
//
// Space Complexity:
// O(n)
//
// Advantage:
// Each rod length solved only once.
//
// ----------------------------------------------------------
// 3. Tabulation (Bottom-Up DP)
//
// Idea:
// Build solutions iteratively from
// smaller rod lengths to larger lengths.
//
// Initialization:
// dp[0] = 0
//
// All other values initialized with INT_MIN
// because initially cuts are impossible.
//
// Transition:
// if(i-x >= 0)
//      dp[i] = max(dp[i], dp[i-x] + 1)
//
// if(i-y >= 0)
//      dp[i] = max(dp[i], dp[i-y] + 1)
//
// if(i-z >= 0)
//      dp[i] = max(dp[i], dp[i-z] + 1)
//
// Time Complexity:
// O(n)
//
// Space Complexity:
// O(n)
//
// Advantage:
// No recursion stack used.
// Efficient iterative DP solution.
//
// ----------------------------------------------------------
// Learning Flow:
//
// Recursion
//    -> understand brute force
//
// Memoization
//    -> optimize repeated calculations
//
// Tabulation
//    -> iterative dynamic programming
//
// ==========================================================
int solveTab(int n, int x, int y ,int z){
vetor<int> dp(m=n+1, INT_MIN);
  dp[0] = 0;
  for(int i=1; i<=n; i++){
    if(i-x >= 0)
        dp[i] = max(dp[i] , dp[i-x] +1);
    if(i-y >= 0)
        dp[i] = max(dp[i], dp[i-y]+1);
    if(i-z >= 0)
        dp[i] = max(dp[i], dp[i-z]+1);
  }
  if(dp[n] < 0)
    
    return 0;
  else
  return dp[n];
}
int cutSegments(int n, int x, int y ,int z){
return solveTab(n,x,y,z);
}




int solveMem(int n, int x, int y ,int z,vector<int>& dp){
//base case 
if(n==0)
  return 0;
if(n<0)
  return INT_MAX;
if(dp[n]!= -1)
    return dp[n];

int a = solveMem(n-x, x,y,z,dp)+1;
int b = solveMem(n-y,x,y,z,dp)+1;
int c= solveMem(n-z, x,y,z,dp)+1;

dp[n] = max(a, max(b,c));
  
return dp[n];
}
int cutSegments(int n, int x, int y ,int z){
vector<int> dp(n+1, -1);
int ans= solveMem(n,x,y,z,dp);
  if(ans<0)
    return 0;
  else
return ans;
}





recursive solution 

int solve(int n, int x, int y ,int z){
//base case 
if(n==0)
  return 0;
if(n<0)
  return INT_MAX;

int a = solve(n-x, x,y,z)+1;
int b = solve(n-y,x,y,z)+1;
int c= solve(n-z, x,y,z)+1;

int ans= max(a, max(b,c));
return ans;
}
int cutSegments(int n, int x, int y ,int z){
int ans= solve(n,x,y,z);
if(ans<0)
  return 0;
else return ans;
}
