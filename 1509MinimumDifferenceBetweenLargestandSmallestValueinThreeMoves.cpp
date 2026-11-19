class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        if(n <= 3) return 0;
        // all three smallest element
        int case1 = nums[n-1] - nums[3];
        //two first elment and one last element 
        int case2 = nums[n-2] - nums[2];
        //one first element and two last element 
        int case3 = nums[n-3]- nums[1];
        //all last element 
        int case4 = nums[n-4] - nums[0];

        return min({case1, case2, case3, case4});
    }
};
