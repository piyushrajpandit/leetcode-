```cpp
// Sliding Window + Product
//
// 1. Use left and right pointers to maintain a sliding window.
// 2. Keep multiple as the product of all elements in the current window.
// 3. Add nums[right] to the product and expand the window.
// 4. If the product becomes >= k, shrink the window from the left
//    until the product becomes < k.
// 5. For every valid window, there are:
//      right - left + 1
//    valid subarrays ending at right.
// 6. Add this value to ans instead of using max(), because we need
//    to count every valid subarray, not just the longest one.
// 7. If k <= 1, return 0 because nums contains positive integers.
//
// Time: O(n)
// Space: O(1)
```


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int left =0;
        int right =0 ;
        int ans =0 ;
        int multiple = 1;
        
        while(right < nums.size()){
           
            multiple *= nums[right];
        
            while(multiple >= k){
                multiple /= nums[left];
                left++;
            }
            ans += right -left + 1;
            right++;
        }
        return ans;
    }
};
