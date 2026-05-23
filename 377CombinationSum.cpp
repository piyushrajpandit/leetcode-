class Solution {
public:
    int solve(vector<int>& num, int tar){
        //base case 
        if(tar<0)
            return 0;
        if(tar==0)
            return 1;
        int ans =0;

        for(int i= 0; i<num.size(); i++){
            ans += solve(num , tar - num[i]);
        }
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums,target );
    }
};


class Solution {
public:
    int solve(vector<int>& num, int tar, vector<int> &dp){
        //base case 
        if(tar<0)
            return 0;
        if(tar==0)
            return 1;
        if(dp[tar]!= -1){
            return dp[tar];
        }
        int ans =0;

        for(int i= 0; i<num.size(); i++){
            ans += solve(num , tar - num[i],dp);
        }
        dp[tar] = ans;
        return dp[tar];
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(nums,target,dp );
    }
};


class Solution {
public:
    int solve(vector<int>& num, int tar){
        //base case 
        vector<unsigned long long > dp(tar +1, 0);
        dp[0]=1;
        // from target 1 to tar
        for(int i=1; i<= tar; i++){
            for(int j= 0; j<num.size();j++){
                if(i-num[j]>=0)
                //taraverse on num vector
                dp[i] += dp[i - num[j]];
            }
        }
        return dp[tar];
        
    }
    int combinationSum4(vector<int>& nums, int target) {
      
        return solve(nums,target );
    }
};
