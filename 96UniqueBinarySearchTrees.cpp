/*
Approach: Dynamic Programming (Tabulation)

dp[i] = Number of unique Binary Search Trees (BSTs) that can be formed
using i nodes.

For each number of nodes i:
    - Try every node j (1 to i) as the root.
    - Left subtree will have (j - 1) nodes.
    - Right subtree will have (i - j) nodes.
    - Total BSTs with root j =
          dp[j - 1] * dp[i - j]
      (multiply because every left subtree can pair with every right subtree)

Recurrence:
    dp[i] += dp[j - 1] * dp[i - j]

Base Cases:
    dp[0] = 1   // Empty tree
    dp[1] = 1   // Single node tree

This follows the Catalan Number recurrence and builds answers
from smaller subproblems to larger ones.

Time Complexity: O(n^2)
Space Complexity: O(n)
*/
class Solution {
public:
    int numTrees(int n) {
        if( n<=1)
          return 1;
        int ans =0; 
        //think i as root node 
        for(int i =1; i<=n; i++){
             ans += numTrees(i-1)*numTrees(n-i);
        } 
        return ans;
    }
};

class Solution {
public:
    int solve(int n,vector<int> & dp) {
        if( n<=1)
         return 1;
        if(dp[n] != -1)
            return dp[n];
        int ans =0; 
         //think i as root node 
        for(int i =1; i<=n; i++){
             ans += solve(i-1,dp)*solve(n-i,dp);
              } 
        return dp[n] = ans;
    }
    int numTrees(int n){
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

class Solution {
public:
    int solve(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] =1 ;

        //i-> nuber of nodes 
        for(int i=2; i<=n; i++){
            //j-> root node 
            for(int j=1; j<= i ; j++){
                dp[i] += dp[j-1]* dp[i-j];
            }
        }
  
    return dp[n];
    }
    int numTrees(int n){
        
        return solve(n);
    }
};
