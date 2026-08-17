/*
1. mid == target
       ↓
    return true

2. nums[left] == nums[mid] == nums[right]
       ↓
    shrink:
    left++
    right--

3. Left half is sorted
   nums[left] <= nums[mid]
       ↓
   target belongs there?
       ↓
   yes → right = mid - 1
   no  → left = mid + 1

4. Otherwise right half is sorted
       ↓
   target belongs there?
       ↓
   yes → left = mid + 1
   no  → right = mid - 1
*/





class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1 ;
        while(left <= right){
        int mid = left + ( right - left ) /2;
        if(nums[mid] == target)
             return true;
        if(nums[left] == nums[mid] && nums[mid] == nums[right]){
            left = left +1;
            right = right - 1;
        }
        else if(nums[left] <= nums[mid] ){
            if(nums[left] <= target &&  target < nums[mid]){
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
            
        }
        else{
            if(nums[mid] <= target &&  target <= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid -1 ;
            }
            
        }
        }
        return false;
    }
};
