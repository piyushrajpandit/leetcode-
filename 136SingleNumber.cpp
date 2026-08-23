// XOR (^) — Quick Summary
// XOR means Exclusive OR. It compares two bits and returns 1 when they are different, and 0 when they are the same.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = 0;
        for(int i =0; i< nums.size(); i++){
            temp = nums[i]^ temp;
        }
        return temp;
    }
};
