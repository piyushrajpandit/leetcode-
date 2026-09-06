// Use the Sliding Window / Two Pointer approach.
// Expand the window by moving right and add nums[right] to sum.
// When sum >= target, the current window is valid.
// Shrink the window from the left while sum >= target
// to find the smallest possible valid subarray.
// Update ans with the minimum window length.
// If no valid subarray exists, return 0.
//
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0; 
        int sum = 0 ;
        int ans = INT_MAX;
       
        
        for(int right = 0 ; right < nums.size() ; right++){
            sum += nums[right];
            while(sum >= target){
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};
