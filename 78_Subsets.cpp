



class Solution {
public:
    void  solve(vector<int> nums, int index  , vector<vector<int>>& ans, vector<int> output){
        //basecase
        if(index >= nums.size()){
            ans.push_back(output);
            return ;

        }
        //exculde case me 
        solve(nums, index+ 1, ans, output);

        //include case
        int element = nums[index];
        output.push_back(element);

        solve(nums, index+1, ans, output );


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, index ,ans, output);
        return ans;

        
    }
};
