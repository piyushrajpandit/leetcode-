class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        sort(nums.begin() , nums.end());
        int diff = 0;
        int ans = 0;
        for(int i =1 ; i <nums.size() ;i++){
          diff =nums[i] - nums[i-1];
            ans = max(ans, diff);

        }
        return ans;
    }

};
