// Use an unordered_map to keep track of numbers that have already appeared.
// For each number:
// 1. If the number is not present in the map, store it.
// 2. If the number is already present, a duplicate exists, so return true.
// 3. If the loop finishes without finding a duplicate, return false.
//
// Time: O(n) average
// Space: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> dq;
        int j =0;
        for(int i =0 ; i< nums.size() ;i++){
            if(dq.find(nums[i]) == dq.end()){
                dq[nums[i]] = j;
                j++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
