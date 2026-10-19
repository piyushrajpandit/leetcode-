class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> answer;
        sort(nums.begin(), nums.end());
        for(int i =0 ;i < nums.size() ; i++){
            if(nums[i] == target){
                answer.push_back(i);
            }
        }
        return answer;
    }
};
