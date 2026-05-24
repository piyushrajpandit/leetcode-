class Solution {
public:
    int solve(vector<int>& nums, int index,int sum, int target) {
        //target acchived 
        if(index == nums.size()){
           if(sum == target)
                return 1;
            return 0;

        }
        int plus = solve(nums,index+1,sum + nums[index],target);

        int minus = solve(nums,index+1,sum - nums[index], target);

       return plus+ minus;
      
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        

        return solve(nums, 0,0,  target);
    }
};
