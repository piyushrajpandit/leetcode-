// we have to muiple of all the element except at which place we are show  first i thought to make a number which is multiple *= nums 
//   for all element but at the time of returning we will /nums[i] and put in answer

// but this is wrong suppose two consecusitive numbers are zero so 0/0 became wrong to solve this we want left suffix and pright suffix approach 
// this is done this way 
// and only we have to do in 0(n) this 
  
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
        int n = nums.size();

        int left = 1 ;
        vector<int> ans(nums.size() , 1);
        for(int i=0; i <n;i++){
            ans[i] = left;
            left *= nums[i];
        }

        int right =1 ;
        for(int i =n-1  ; i >= 0 ; i--){
            ans[i] *= right;
            right *= nums[i];

        }
        return ans ;
   }
};
