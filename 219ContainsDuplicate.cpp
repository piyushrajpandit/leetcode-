// Use an unordered_map to store the last index of each number.
// For every element:
// 1. If the number is already in the map, get its previous index.
// 2. Check if the distance between the current and previous index is <= k.
// 3. If yes, a nearby duplicate exists, so return true.
// 4. Update the number's index to the current index.
// 5. If the number is not present, store its current index.
// 6. If no nearby duplicate is found, return false.
//
// Time: O(n) average
// Space: O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dq; 
       
        for(int i =0 ; i< nums.size() ; i++){
            if(dq.find(nums[i]) != dq.end()){
                int previousIndex = dq[nums[i]];
                if(i - previousIndex <= k)
                    return true;
                dq[nums[i]] = i;

            }
            else{
                dq[nums[i]] = i;
            }
        }
        return false;
    }
};
