class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> dp;
        for(int i = 0; i < nums.size(); i++){
            dp[nums[i]]++;
        }
        int ans = 0;
        int element =0 ;
        for(auto x: dp){
            if(x.second > ans){
                ans = x.second;
                element = x.first;
            }
        }
        return element;
    }
};
