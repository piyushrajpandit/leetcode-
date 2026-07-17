class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int j=1;
        int missing = -1;
        
        for(int i =0 ; i< nums.size() ; i++){
            
            if(i > 0 && nums[i] == nums[i - 1]){
                ans.push_back(nums[i]);
            }
            while(j< nums[i]){
                 missing = j;
                 break;
            }
            j = nums[i]+1;

        }
        if (missing == -1)
            missing = nums.size();

        ans.push_back(missing);
        return ans;
    }
};
