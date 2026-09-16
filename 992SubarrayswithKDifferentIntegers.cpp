// Sliding Window + At Most K Trick
//
// atMost(k) = number of subarrays having <= k distinct elements.
//
// Maintain a window [left, right] with at most k distinct values.
// Add nums[right] and increase its frequency.
//
// If distinct count > k:
//     Move left forward until the window becomes valid.
//
// For every valid window:
//     right - left + 1
// subarrays ending at right are valid.
//
// Exactly K distinct:
//     atMost(k) - atMost(k - 1)
//
// Time: O(n)
// Space: O(k)
class Solution {
public:
    long long atMost(vector<int>& nums, int k){
        int left = 0 ;
        int right = 0 ;
        long long ans = 0;
        int count = 0;
        unordered_map<int ,int > dp;
        while(right < nums.size()){
            if(dp.find(nums[right]) == dp.end()){
                count++;
            }
            dp[nums[right]]++;
           
            while(count > k){
                if(dp[nums[left]] == 1){
                    dp.erase(nums[left]);
                    count--;
                }
                else
                dp[nums[left]]--;
                left++;
            }
                ans += right - left + 1;




            right++;

        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums , k ) - atMost(nums, k-1);
    }
};
