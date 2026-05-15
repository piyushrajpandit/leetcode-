// 1. Recursive Approach
// Idea

// At each stair n, the minimum cost is:

// cost[n]+min(f(n−1),f(n−2))

// f(n)=cost[n]+min(f(n−1),f(n−2))

// The recursion explores both possible paths:

// one step jump
// two step jump
// Base Cases
// n == 0 → cost[0]
// n == 1 → cost[1]
// Drawback

// This approach recalculates the same states many times, causing exponential time complexity.

// Time Complexity:

// O(2
// n
// )

// O(2
// n
// )

// 2. Memoization (Top-Down DP)
// Idea

// Use a dp[] array to store already computed answers.

// Before calculating a state:

// check if answer already exists in dp[]
// if yes, return stored value
// Benefit

// Avoids repeated recursive calculations.

// Important Point

// dp must be passed by reference:

// vector<int>& dp

// Otherwise every recursive call creates a copy and memoization fails.

// Complexity

// Time:

// O(n)

// Space:

// O(n)

// O(n) time, O(n) space

// 3. Tabulation (Bottom-Up DP)
// Idea

// Instead of recursion:

// build answers iteratively from smaller states.
// DP Definition
// dp[i]=cost[i]+min(dp[i−1],dp[i−2])

// dp[i]=cost[i]+min(dp[i−1],dp[i−2])

// Steps
// Create dp[]
// Initialize base cases
// Fill DP array from left to right
// Final answer:
// min(dp[n-1], dp[n-2])

// because top can be reached from either last stair or second-last stair.

// Complexity

// Time:

// O(n)

// Space:

// O(n)
// 4. Space Optimization

// Observation:
// To compute current state, only previous two states are needed.

// So instead of using full dp[]:

// use two variables:
// prev1
// prev2

// This reduces space complexity to:

// O(1)

// O(1) space



// time complexity o(n)
// o(n) + o(n) space for recursion
 // o(n) for tabulation 
// here anwer contain 4 different solutoion 
// 4. using prevois and current 
// space (o(1)) this is the sicnificance of this code 

// 1 tabulation
//  tc o(n) 
// sc(o(n) 
  
// 2. dp + recussion plus memiriztion 
// tc o(n) 
// sc o(n)+o(n)
// 3. recurssion 
//    this is the brute force approcch 



//   tabulation 
// here we make dp and in dp we add 
// from 0 to n

// and then dp 


// and first is this recussion 


int solve4(vector<int> & cost , int n){
int prev2 = cost[0];
int prev1 =  cost[1];
for(int i=2; i<n;i++){
int curr = cost[i] + min{prev1, prev2);
prev2= prev1;
prev1 = curr;
}
return min(prev1, prev2);
}
int minCostClimbingStrairs(vector<int> & cost){
int n= cost,size();
return solve4(cost, n);
}



class Solution {
public:

    // Tabulation Approach
    int solve3(vector<int>& cost, int n) {

        // Step 1: Create DP array
        vector<int> dp(n + 1);

        // Step 2: Base cases
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Step 3: Fill DP array
        for(int i = 2; i < n; i++) {

            dp[i] = cost[i] +
                    min(dp[i - 1], dp[i - 2]);
        }

        // Final answer
        return min(dp[n - 1], dp[n - 2]);
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        return solve3(cost, n);
    }
};




//this is code with dp 
// this is the best code 


class Solution {
public:
    int solve (vector<int>& cost, int n ,vector<int>& dp){
        //base case 
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];

        if(dp[n]!= -1){
            return dp[n];
        }    

        dp[n]= cost[n] + min(solve(cost,n-1,dp), solve(cost, n-2,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //it can be simplified more
        vector<int>dp (n+1, -1);
        
        int ans= min(solve(cost, n-1,dp), solve(cost,n-2,dp));
        return ans;
    }
};



//but this code will give tle 
class Solution {
public:
    int solve (vector<int>& cost, int n ){
        //base case 
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];
        int ans = cost[n] + min(solve(cost,n-1), solve(cost, n-2));
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        //it can be simplified more
        int ans= min(solve(cost, n-1), solve(cost,n-2));
        return ans;
    }
};
