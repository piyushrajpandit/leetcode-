/*
LeetCode 1760 - Minimum Limit of Balls in a Bag

Idea:
Binary search for the minimum possible maximum number of balls
that can remain in any bag.

left = 1
right = maximum element in nums

For each mid:
    Treat mid as the maximum allowed balls in one bag.

For every num:
    required pieces = ceil(num / mid)
    operations needed for this bag = required pieces - 1

    Add these operations to the total.

Why pieces - 1?
    1 bag -> 2 bags = 1 operation
    1 bag -> 3 bags = 2 operations
    So operations = pieces - 1

If total operations <= maxOperations:
    mid is possible, so try a smaller maximum size.
    right = mid

Else:
    mid is too small because it requires too many operations.
    left = mid + 1

At the end:
    left is the smallest possible maximum bag size.

Important:
    Operations must be calculated and accumulated for EVERY bag,
    not just the last bag.
*/

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left =1 ;
        int right = *max_element(nums.begin(), nums.end());
        while(left < right){
            int mid = left + (right - left ) /2 ;
          
            int temp = 0;
            for(auto num : nums){
                temp += (num- 1)/ mid ;
                
            }
            int operation = temp  ;
            if(operation <= maxOperations){
                right = mid;
            }
            else{
                left = mid + 1 ;
            }
        }
        return left;
    }
};
