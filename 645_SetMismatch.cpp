// Calculate the expected sum and square sum from 1 to n.
// Calculate the actual sum and square sum of the given array.
// Difference of sums gives: D - M.
// Difference of square sums gives: D² - M².
// Using (D² - M²) = (D - M)(D + M), find D + M.
// Calculate D (missing number) using D-M and D+M.
// Calculate M (duplicate number) using D - (D-M).
// Return [M, D].

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        long long actualsum = 1LL*(n*(n+1))/2;
        long long sum = 0;
        long long actualsquareSum =  1LL * n * (n + 1) * (2 * n + 1) / 6;
        long long squaresum = 0;
        for(int i=0 ; i< nums.size() ; i++){
            sum += nums[i];
            squaresum += nums[i]* nums[i];
        }
        long long temp = actualsum- sum;
        long long temp2 = actualsquareSum - squaresum;
       
        long long sumMD = temp2/temp;
      
        long long D = (temp + sumMD) /2;
        long long M =  D  -temp;
        ans.push_back(M);
        ans.push_back(D);
        return ans;
    }
};
