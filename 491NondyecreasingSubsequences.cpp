class Solution {
public:
    void back(vector<int>& nums , int index, vector<int>&temp , vector<vector<int>>& answer){
        if(temp.size() >= 2){
            answer.push_back(temp);
        }
        unordered_set<int> used;
        for(int i = index; i <nums.size(); i++){
            if(used.count(nums[i])) continue;
            if(!temp.empty() && nums[i] < temp.back())
                continue;
            used.insert(nums[i]);
            temp.push_back(nums[i]);
            back(nums, i+1, temp, answer);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<vector<int>> answer;
        vector<int> temp;
        back(nums, 0,temp, answer);
        return answer;
    }
};
