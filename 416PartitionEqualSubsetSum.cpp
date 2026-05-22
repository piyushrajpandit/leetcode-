class Solution {
public:
     bool solve(vector<int>& nums, int index,int target,vector<vector<int>> &dp){
        if(target ==0)
            return true;

        if(index<0)
            return false;
        

        //alrady solved 
        if(dp[index][target] != -1)
            return dp[index][target];


        //include current elemnt 
        bool include = false;
        if(nums[index] <= target)
            include = solve(nums, index-1, target - nums[index],dp);
        
        //exclude current element 
        bool exclude = solve(nums, index-1 , target,dp);

        dp[index][target] = include || exclude ;
        return dp[index][target];
        

    }
    bool canPartition(vector<int>& nums) {
        
        int totalSum = 0;
        for(int num: nums)
            totalSum += num;

        //if total sum is odd, impossible 
        if(totalSum%2 != 0)
            return false;
        int target = totalSum /2;
        vector<vector<int>> dp(nums.size(), vector<int>(target +1 ,-1) );
        return solve(nums, nums.size() -1 , target,dp);
    }
};
