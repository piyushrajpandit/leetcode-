/*
    LeetCode 45 - Jump Game II
    Greedy Approach

    Idea:
    - nums[i] tells how far we can jump from index i.
    - Instead of checking every possible path, maintain the farthest
      index we can reach within the current jump range.

    Variables:
    - jumps:
        Number of jumps taken so far.

    - currentEnd:
        Last index reachable using the current number of jumps.

    - farthest:
        Farthest index we can reach from all positions in the
        current range.

    Logic:
    - For every index i, calculate how far we can reach:
          i + nums[i]

    - Update the farthest reachable position:
          farthest = max(farthest, i + nums[i]);

    - When i reaches currentEnd, we have finished exploring the
      current jump range.
      Therefore, take another jump:
          jumps++;
          currentEnd = farthest;

    - Stop at nums.size() - 1 because once we reach the last index,
      no additional jump is needed.

    Example:
        nums = [2,3,1,1,4]

        First range: [0,1,2]
        Farthest from this range = 4

        Jump 1 → reach range ending at 2
        Jump 2 → reach index 4

        Answer = 2

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int currentEnd = 0;
        int farthest = 0;
        for(int i =0 ; i< nums.size()- 1; i++){
            farthest = max(farthest , i+ nums[i]);
            if( i == currentEnd){
                jump++;
                currentEnd = farthest;
            }
        }
        return jump;
    }
};
