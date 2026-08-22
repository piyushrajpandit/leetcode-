/*
LeetCode 16 - 3Sum Closest

Idea:
Use sorting + two pointers.

1. Sort the array.
2. Fix one element using index i.
3. Set:
       left = i + 1
       right = n - 1
4. Calculate:
       sum = nums[i] + nums[left] + nums[right]
5. Calculate the distance from target:
       newDist = abs(target - sum)
6. If newDist is smaller than the best distance found:
       ans = sum
       dist = newDist

Pointer movement:
    if sum < target:
        left++      // need a larger sum

    else if sum > target:
        right--     // need a smaller sum

    else:
        sum == target
        // exact answer, distance is 0

Important:
    dist must start with a very large value:
        int dist = INT_MAX;

    ans stores the actual three-number SUM,
    not the distance from target.

Why two pointers work:
    The array is sorted, so:
        moving left  → increases the sum
        moving right → decreases the sum

Time Complexity: O(n²)
Space Complexity: O(1) excluding sorting space.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left ;
        int right ;
        int dist = INT_MAX;
        int ans = 0 ;
        for(int i =0 ; i< nums.size(); i++){
                left = i + 1;
                right = nums.size() -1;

            while(left  < right){
                int sum = nums[i] + nums[left]+ nums[right];
                int newDist = abs(target - sum);
                
                if(newDist < dist){
                    ans = sum;
                    dist = newDist;
                }
                if(sum == target){
                    return sum;
                }
               
                if(sum < target ){
                    left++;
                }
                if(sum > target){
                    right--;
                }
            }
        }
        return ans;
    }
};
