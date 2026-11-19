class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        if(n <=3) return 0;
        //two smallest element 
        int case1 = nums[n-1] - nums[2];
        //two largest
        int case2 = nums[n-3] - nums[0];
        // one smallest one largest
        int case3 = nums[n-2]- nums[1];

        return min({case1, case2, case3});
    }
};
