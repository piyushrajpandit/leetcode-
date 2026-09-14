// Sliding Window + HashMap
//
// Goal:
// Find maximum sum of a subarray of exactly k elements
// where all k elements are distinct.
//
// 1. Maintain a window of exactly k elements using left/right.
// 2. `sum` stores the current window sum.
// 3. `freq` stores frequency of each element in the window.
// 4. When right moves:
//      - Add nums[right] to sum and freq.
//      - Remove nums[left] to keep window size k.
//      - Move left forward.
// 5. If freq.size() == k:
//      - All k elements are distinct.
//      - Update ans = max(ans, sum).
//
// Complexity:
// Time  : O(n)
// Space : O(k)
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
   
        int left = 0 ;
        long long sum = 0;
        int right = 0;
        long long ans = 0;
        unordered_map<int,int> freq;
        for(right = 0 ; right < k ;right++){
            sum += nums[right];
            freq[nums[right]]++;
        }
        if(freq.size() == k){
            ans = max(ans, sum);
        }
        right =k;
        while(right< nums.size()){
            sum += nums[right];
            freq[nums[right]]++;
           
            sum -= nums[left];
            freq[nums[left]]--;
                
            if(freq[nums[left]] == 0){
                freq.erase(nums[left]);
            }
            left++;

            
            if(freq.size() == k){
                ans = max(ans, sum);
            }
            right++;
        }
    return ans;
    }
};
