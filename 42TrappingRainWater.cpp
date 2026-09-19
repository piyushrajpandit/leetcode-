/*
    Trapping Rain Water - Two Pointer Approach

    Idea:
    - Water at an index depends on the smaller of the maximum height
      on its left and right.
    - Use two pointers: left and right.
    - Maintain leftMax and rightMax.

    Logic:
    - If height[left] <= height[right]:
        -> Process the left side because the right side has a boundary
           at least as high as height[left].
        -> If height[left] > leftMax, update leftMax.
        -> Otherwise, water trapped = leftMax - height[left].
        -> Move left forward.

    - Otherwise:
        -> Process the right side.
        -> If height[right] > rightMax, update rightMax.
        -> Otherwise, water trapped = rightMax - height[right].
        -> Move right backward.

    Why this works:
    - The smaller boundary determines the amount of water.
    - When processing the left, we already know the right boundary is
      high enough, so only leftMax is needed.
    - Similarly, when processing the right, only rightMax is needed.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0 ;
        int right = height.size() -1;
        int ans;
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        while(left < right){
            if(height[left] <= height[right]){

                if(height[left] > leftMax){
                    leftMax = height[left];
                }
                else{
                    ans += left - height[left];
                }
                left++;
            }
            else{

                if(height[right] > rightMax){
                    rightMax = height[right];
                }
                else{
                    ans += rightMax - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};
