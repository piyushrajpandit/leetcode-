/*
    LeetCode 152 - Maximum Product Subarray
    Dynamic Programming Approach

    Idea:
    - At every index, keep track of both the maximum and minimum
      product of a subarray ending at the current index.
    - We need both because multiplying by a negative number can
      turn the minimum negative product into the maximum positive product.

    Variables:
    - currentMax:
        Maximum product of a subarray ending at the current index.

    - currentMin:
        Minimum product of a subarray ending at the current index.

    - ans:
        Maximum product found so far.

    For every nums[i], there are 3 possibilities:
    1. Start a new subarray from nums[i].
    2. Extend the previous maximum product:
           currentMax * nums[i]
    3. Extend the previous minimum product:
           currentMin * nums[i]

    Therefore:
        newMax = max(nums[i],
                     currentMax * nums[i],
                     currentMin * nums[i])

        newMin = min(nums[i],
                     currentMax * nums[i],
                     currentMin * nums[i])

    Important:
    - Calculate newMax and newMin using the OLD currentMax
      and currentMin before updating them.
    - This is necessary because a negative number can swap
      the roles of maximum and minimum.

    Example:
        nums = [-2, 3, -4]

        At -4:
        currentMax = 3
        currentMin = -6

        3 * -4  = -12
        -6 * -4 = 24
        -4       = -4

        newMax = 24

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
     
        int currentMin = nums[0];
        int currentMax = nums[0];
        int ans = nums[0];
        int newMax = 0;
        for(int i=1 ; i< nums.size() ;i++){
            newMax = max(nums[i],
            max(currentMax * nums[i],currentMin * nums[i])
            );
            int newMin = min(nums[i], 
            min(currentMax * nums[i], currentMin * nums[i])
            );
            currentMax = newMax;
            currentMin = newMin;
           
            ans = max(ans, currentMax);
        }
      
        return ans;
    }
};
