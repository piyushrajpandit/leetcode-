
268
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Sum of numbers from 0 to n
        int sum = (n * (n + 1)) / 2;

        // Subtract every number present in nums.
        // The remaining value is the missing number.
        for(int i = 0; i < nums.size(); i++){
            sum -= nums[i];
        }

        return sum;
    }
};
