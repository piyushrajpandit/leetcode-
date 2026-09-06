// Sort the array so consecutive numbers come next to each other.
// Keep j as the length of the current consecutive sequence.
// If nums[i] + 1 == nums[i+1], extend the sequence.
// If duplicate numbers are found, ignore them without resetting j.
// If the sequence breaks, reset j to 1 because the current number
// starts a new sequence.
// Keep maxi as the maximum consecutive sequence length found.
// Handle an empty array separately.
// Time: O(n log n) due to sorting.
// Space: O(1) extra space (excluding sorting space).

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int j =1 ;
        int maxi = 1;
        if(nums.empty()) return 0;
        for(int i =0 ; i< nums.size() ;i++){
            int temp = i;

            if( i  +1 < nums.size() && nums[i] + 1 == nums[i+1]){
                j++;
                maxi = max( j , maxi);
            }
            else if( i + 1 < nums.size() && nums[i] == nums[i + 1]){
                continue;
            }
            else{j= 1;}
        }
        return maxi;
    }
};
