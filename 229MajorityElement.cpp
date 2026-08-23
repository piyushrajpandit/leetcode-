
229
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // IDEA:
        // Count the frequency of every element using a hashmap.
        // Key   = element
        // Value = frequency of that element

        unordered_map<int, int> freq;
        vector<int> ans;

        // Step 1: Count frequency of each element.
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        // Step 2:
        // An element is a majority element if it appears
        // more than floor(n / 3) times.
        int temp = nums.size() / 3;

        // Step 3: Check every element's frequency.
        for(auto num : freq){
            if(num.second > temp)
                ans.push_back(num.first);
        }

        return ans;
    }
};
