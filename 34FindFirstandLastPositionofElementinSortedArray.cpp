class Solution {
public:
    int Binary(vector<int>&nums, int start, int end,int target){
        if(start > end)
            return -1;
        int mid = start + (end- start)/2;
        if(nums[mid]== target){
            return mid;
        }
        if( target<nums[mid]){
        return Binary(nums, start , mid-1,target);
        }
        else
        return Binary(nums, mid+1, end,target);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int start = 0; 
        int end = nums.size()-1;
        int mid = start + (end- start)/2;
        int ans =Binary(nums, 0, end, target);
        if(ans == -1)
            return {-1, -1};
        int left = ans;
        int right = ans;

        while (left > 0 && nums[left - 1] == target)
            left--;

        while (right < nums.size() - 1 && nums[right + 1] == target)
            right++;

        result.push_back(left);
        result.push_back(right);    
        return result;
    }
};
