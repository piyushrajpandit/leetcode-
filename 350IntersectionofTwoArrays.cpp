class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(auto num1 : nums1){
            for(int j =0 ; j< nums2.size(); j++){
                if(num1 == nums2[j] && nums2[j] != -1){
                    nums2[j] = -1 ;
                    result.push_back(num1);
                    break;}
                    
                    
            }
        }
       
        return result;
    }
};

// Approach:
// 1. Traverse each element of nums1.
// 2. For every element, search for a matching unused element in nums2.
// 3. When a match is found, add it to result.
// 4. Mark the matched element in nums2 as -1 so it cannot be reused.
// 5. Break after a match so one element of nums1 is matched only once.
//
// Time Complexity: O(n * m)
// Space Complexity: O(min(n, m)) for the result
