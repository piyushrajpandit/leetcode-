class Solution {
public:
 
    int solve(int amount , vector<int> & coins, int index,int sum,vector<vector<int>> & dp){
        if(amount == sum){
     
            return 1;
        }
        if(index >= coins.size() || sum > amount)
            return 0;
        if(dp[index][sum] != -1)
            return dp[index][sum];
        int take = solve(amount, coins, index,sum + coins[index],dp);
     
        int notTake = solve(amount, coins, index+ 1,sum,dp);
        return dp[index][sum] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        
        return solve(amount, coins, 0,0,dp);
    }
};
