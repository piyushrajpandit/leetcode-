class Solution {
public:

    int solve(vector<int>& nums, int i) {

        if(i >= nums.size()) {
            return 0;
        }

        // Take current number
        int take = nums[i];

        int j = i + 1;

        while(j < nums.size() && nums[j] == nums[i]) {
            j++;
        }

        int next = j;

        // Skip consecutive number
        if(j < nums.size() && nums[j] == nums[i] + 1) {
            while(j < nums.size() && nums[j] == nums[i] + 1) {
                j++;
            }
        }

        take = (nums[i] * (next - i)) + solve(nums, j);

        // Don't take current number
        int skip = solve(nums, next);

        return max(take, skip);
    }

    int deleteAndEarn(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        return solve(nums, 0);
    }
};



class Solution {
public:
    int solve(vector<int> &nums,int i,vector<int> & dp){
        if( i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1 ){
            return dp[i];
        }
        int take = nums[i];
        int j = i+1;
        while(j< nums.size() && nums[j] == nums[i]){
            j++;
        }
        int next = j;
        //skip consecutive numbers 
        if(j< nums.size() && nums[j] == nums[i]+ 1 ){
            while(j< nums.size() && nums[j] == nums[i] +1){
                j++;
            }
        }
        take = (nums[i] * (next -i)) + solve(nums, j,dp);
        //dont take current number 
        int skip = solve(nums, next,dp);
        return dp[i] = max(take , skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        sort(nums.begin(), nums.end());
        return solve(nums,0 ,dp);

    }
};
