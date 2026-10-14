class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        int sign = 1;
        int count = 0;
        int ans = INT_MIN;
        for(int i =0 ; i< nums.size()-1; i++){
            if(sign == 1){
                if(nums[i] < nums[i+1]){
                    count++;
                    sign = -1;
                }
                else if( nums[i] > nums[i+1]){
                    count++;
                    sign = 0;
                }
            }
           
            else if(sign == -1){
                if(nums[i] > nums[i+1]){
                    count++;
                    sign = 0;
                    
                }
            }
            else{
                if(nums[i] < nums[i+1]){
                    count++;
                    sign = -1;
                }
            
            }
        }
        return count+1;
    }
};
