/*
My confusion:
Do we need to pass a count parameter to solve() to track how many elements
we have selected? No, because index already tracks the position we are filling.
When index == nums.size(), the permutation is complete.

We use an unordered_set<int> called used to avoid duplicate choices at the
same recursion level. Each recursive call creates its own used set, so the
same value can be chosen at different positions in different branches.

Remember: index tracks progress, used prevents duplicate choices at the
current level, and backtracking (swap back) restores the array for the next choice.
*/

class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>>& ans, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int> used;
        for(int j = index ;j< nums.size(); j++){
            if(used.count(nums[j]){
                continue;
            }
            used.insert(nums[j]);
            swap(nums[index], nums[j]);
            solve(nums, ans ,index+1);
            swap(nums[index], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        
        solve(nums, ans, index);
        return ans;
    }
};
