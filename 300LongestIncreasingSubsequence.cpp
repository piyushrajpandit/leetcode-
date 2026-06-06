class Solution {
public:
    int solve(vector<int> &a, int n, int curr, int prev){
        //base case 
        if(curr == n){
            return 0;
        }
        //include 
        int take =0;
        if(prev == -1 || a[curr] > a[prev])
            take = 1 + solve(a, n, curr+1, curr);

        //exclude 
        int notTake = 0 + solve(a, n, curr+ 1 , prev);

        return max(take , notTake);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, n, 0, -1);

    }
};
