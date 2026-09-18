/*
    LeetCode 1838 - Frequency of the Most Frequent Element

    Approach: Sorting + Sliding Window

    1. Sort the array.
       This lets us make all elements in a window equal to
       nums[right], because all elements before right are <= nums[right].

    2. Maintain a sliding window:
           [left ... right]

       `sum` = sum of all elements inside the window.

    3. To make every element in the window equal to nums[right],
       calculate the required operations:

           required = nums[right] * windowSize - sum

       Example:
           [1, 2, 4]
           target = 4

           required = 4 * 3 - 7
                    = 5

    4. If required > k:
       The current window needs too many operations.
       Remove elements from the left until the window becomes valid.

           sum -= nums[left];
           left++;

       Recalculate required after moving left.

    5. If required <= k:
       The current window can be made equal to nums[right].
       Update the maximum frequency:

           ans = max(ans, right - left + 1);

    6. Important:
       - `k` is the maximum allowed operation budget.
       - DO NOT decrease k.
       - Use `long long` for sum and required.
       - Do not redeclare `required` inside the while loop.
         Otherwise you create a new variable and the outer
         required value never gets updated.

    Main idea:

        Sort
          ↓
        Expand right
          ↓
        Calculate required operations
          ↓
        required > k → shrink from left
          ↓
        required <= k → update maximum window size

    Time Complexity: O(n log n)
        O(n log n) for sorting + O(n) sliding window

    Space Complexity: O(1) extra space
        (ignoring the sorting implementation)
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int ans = 0;
        long long sum =0;
        while(right < nums.size()){
            sum += nums[right];
            long long requied = 1LL *nums[right]*(right - left + 1) -sum;
            while(requied > k){
                sum -= nums[left];
                
                left++;
                 requied = 1LL *nums[right]*(right - left + 1) -sum;

            }
            if(requied <= k ){
                ans = max( ans, right - left + 1);

            }
            right++;
        }
        return ans;
    }
};
