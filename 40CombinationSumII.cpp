class Solution {
public:
    void back(vector<int> & candidates, int index, int target ,int sum , vector<int>& temp , vector<vector<int>> & answer){
        if(sum == target){
            
            answer.push_back(temp);
            return;
        }
        if(sum > target || index >= candidates.size()){
            return ;
        }
        if(sum + candidates[index] <= target){
            temp.push_back(candidates[index]);
            back(candidates,index+1, target, sum+ candidates[index], temp, answer);
            temp.pop_back();
        }
        int next = index +1;
        while(next < candidates.size() && candidates[next] == candidates[index]){
            next++;
        }
        back(candidates, next, target, sum , temp, answer);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() ,candidates.end());
        vector<vector<int>> answer;
        vector<int> temp;
        back(candidates, 0, target, 0, temp , answer);
        return answer;
    }
};
