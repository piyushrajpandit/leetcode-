// Sliding Window + At Most technique
//
// We need to count subarrays whose sum is exactly equal to goal.
// Instead of counting exact sums directly, use:
//
//     exactly(goal) = atMost(goal) - atMost(goal - 1)
//
// atMost(goal) counts all subarrays whose sum is <= goal.
//
// 1. Use a sliding window with left and right pointers.
// 2. Add nums[right] to the current sum.
// 3. If sum > goal, move left forward until sum <= goal.
// 4. For every valid window, the number of subarrays ending at right is:
//        right - left + 1
// 5. Return atMost(goal) - atMost(goal - 1).
//
// This works because nums contains only 0s and 1s.
//
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atMost(nums,goal) - atMost(nums, goal -1);
    }
    int atMost(vector<int> & nums, int goal){
        if(goal < 0)
            return 0;
        int left = 0;
        int ans = 0;
        int sum = 0;
        for(int right = 0 ; right < nums.size() ; right++){
            sum += nums[right];

        while(sum > goal){
            sum -= nums[left];
            left++;
        }
        ans += right - left + 1;
        }
        return ans;
    }
};
