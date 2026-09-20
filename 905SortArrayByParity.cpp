class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());
        int left = 0 ;
        int right = nums.size()-1;

        for(int i =0 ; i< nums.size() ;i++){
            if(nums[i] %2 == 0){
                ans[left] = nums[i];
                left++;
            }
            else{
                ans[right] = nums[i];
                right--;
            }
        }
    
    return ans;
    }
};
