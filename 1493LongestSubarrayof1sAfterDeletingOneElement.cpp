class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0; 
        int right = 0;
        int ans = 0;
        
        int zeroCount = 0;
        int length = 0;
        while(right < nums.size()){
            if(nums[right] == 0){
                zeroCount++;
            }
            while(zeroCount > 1){
                if(nums[left] == 0) zeroCount--;
                left++;
            
            }
            
            length = right - left;

            ans = max(ans , length);
            right++;
        }
        return ans;
    }
};
