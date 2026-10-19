class Solution {
public:
    void backtracking(vector<int>& nums,int index , vector<int>& temp, vector<vector<int>> &answer){
     
            answer.push_back(temp);
           
        
        for(int i=index ; i< nums.size() ;i++){
            if(i > index && nums[i] == nums[i -1] ){
                continue;
            }
            temp.push_back(nums[i]);
            backtracking(nums,  i+1, temp, answer);
            temp.pop_back();
            

        }
        

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> answer;
        backtracking(nums, 0, temp , answer);
        return answer;
    }
};
