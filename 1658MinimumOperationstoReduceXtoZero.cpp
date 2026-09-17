/*
    LeetCode 1658 - Minimum Operations to Reduce X to Zero

    Approach: Sliding Window

    Key observation:
    Instead of finding elements to REMOVE with sum = x,
    find the longest subarray to KEEP with sum:

        target = totalSum - x

    Because:
        removedSum = totalSum - keptSum
        x = totalSum - keptSum
        keptSum = totalSum - x

    Steps:
    1. Calculate totalSum of the array.
    2. Calculate:
           target = totalSum - x

    3. If target < 0:
           return -1
       because even removing the entire array cannot reach x.

    4. If target == 0:
           return nums.size()
       because we need to remove the entire array.

    5. Use a sliding window to find the LONGEST subarray
       whose sum equals target.

       - right expands the window and adds nums[right]
       - if sum > target, move left forward and subtract nums[left]
       - when sum == target, update maxWindowLength

    6. The elements outside the longest kept subarray are removed.

           answer = nums.size() - maxWindowLength

    Important:
    - nums contains positive integers, so sliding window works.
    - `maxWindowLength` must use max(), because we need the
      LONGEST valid subarray.
    - Do not increment `right` manually because the for-loop does it.

    Example:
        nums = [3,2,20,1,1,3], x = 10

        totalSum = 30
        target = 30 - 10 = 20

        Longest subarray with sum 20 = [20]
        maxWindowLength = 1

        answer = 6 - 1 = 5

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left =0;
        int sum = 0;
        int maxWindowLength = -1;
        int totalSum = 0;
        for(int i =0 ; i< nums.size() ; i++){
            totalSum += nums[i];
        }
        int target = totalSum - x;
        if(target < 0)
            return -1;
        for(int right = 0; right < nums.size() ; right++){
            sum += nums[right];
            while(sum > target && left <= right){
                sum -= nums[left];
                left++;
            }
            if(sum == target){
                maxWindowLength = max( maxWindowLength, right - left + 1);
            }
            
        }
        if(maxWindowLength == -1)   
            return -1;
        int answer = nums.size() - maxWindowLength;
        return answer;
    }
};
