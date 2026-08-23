454
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    
        int count = 0;

        // IDEA:
        // We need: nums1[i] + nums2[j] + nums3[k] + nums4[l] = 0
        //
        // Rearrange:
        // (nums1[i] + nums2[j]) = -(nums3[k] + nums4[l])
        //
        // Step 1:
        // Store every possible sum of nums1 + nums2 in a hashmap.
        // Key   = sum
        // Value = frequency of that sum
        unordered_map<int, int> sum;

        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                int temp = nums1[i] + nums2[j];

                // Store how many times this sum occurs.
                sum[temp]++;
            }
        }

        // Step 2:
        // Generate every possible sum of nums3 + nums4.
        // For a sum "temp", we need "-temp" from nums1 + nums2.
        for(int i = 0; i < nums3.size(); i++){
            for(int j = 0; j < nums4.size(); j++){
                int temp = nums3[i] + nums4[j];

                // Check whether the required opposite sum exists.
                if(sum.find(-temp) != sum.end()){

                    // Add its frequency because multiple pairs
                    // from nums1 + nums2 may produce the same sum.
                    count += sum.find(-temp)->second;
                }
            }
        }

        return count;
    }
};
