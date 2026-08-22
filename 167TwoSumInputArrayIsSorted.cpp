/*
LeetCode 167 - Two Sum II

Idea:
Use two pointers because the array is already sorted.

left  = 0
right = last index

While left < right:
    Calculate:
        sum = numbers[left] + numbers[right]

    If sum == target:
        We found the required pair.
        Return their 1-based indices.

    If sum < target:
        The sum is too small.
        Move left forward to get a larger value.

    If sum > target:
        The sum is too large.
        Move right backward to get a smaller value.

Why this works:
Because the array is sorted, moving left increases the sum
and moving right decreases the sum.

Important:
LeetCode asks for 1-based indices, so return:
    left + 1
    right + 1

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() -1 ;
        
        vector<int> ans;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
            if(sum < target){
                left++;
            }
            if(sum > target){
                right--;
            }
        }
        return ans;
    }
};
