```cpp
// Sliding Window approach
//
// 1. Use left and right pointers to maintain a sliding window.
// 2. Count how many 0s are present in the current window.
// 3. If the number of 0s <= k, the window is valid because
//    we can flip all those 0s into 1s.
// 4. Update ans with the current window length.
// 5. If the number of 0s > k, the window is invalid.
//    Remove nums[left] from the window and move left forward.
// 6. Move right forward after every iteration.
//
// Time: O(n)
// Space: O(1)
```
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        vector<int> count(2, 0);
        int maxFreq =0;
        while(right< nums.size()){
            count[nums[right]]++;
            maxFreq = max(maxFreq , count[nums[right]]);
            if(count[0] <= k){
                ans = max(ans, right -left + 1);
            }
            else{
                count[nums[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};
