/*
================ Minimum Difference Between Highest and Lowest of K Scores =================

Problem:
Choose exactly k elements such that the difference between the
maximum and minimum selected elements is minimum.

Greedy Idea:
1. Sort the array.
2. In a sorted array, the optimal k elements will always be contiguous.
3. Use a sliding window of size k.
4. For each window, compute:
       difference = nums[i + k - 1] - nums[i]
5. Return the minimum difference among all windows.

Why Sorting?
Sorting places similar values together, so every possible group of
k consecutive elements represents a candidate solution.

Algorithm:
- Sort the array.
- Initialize a window of size k.
- Slide the window one element at a time.
- Update the minimum difference.

Time Complexity : O(n log n)
    - Sorting : O(n log n)
    - Sliding Window : O(n)

Space Complexity : O(1) (excluding sorting space)

Pattern:
Sort + Fixed Size Sliding Window

Formula:
Difference = nums[i + k - 1] - nums[i]
Answer = Minimum difference over all windows.
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i =0 ; 
        int j = k-1;
        int mini = INT_MAX;
        int ans = INT_MAX;
        while(j< nums.size()){
            int diff = nums[j] - nums[i];
            ans = min(ans, nums[i + k - 1] - nums[i]);
            i++;
            j++;
        }
        return ans;
    }
};
