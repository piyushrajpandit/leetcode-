
class Solution {
public:

    void back( int index, int target ,int sum ,
    vector<int>& temp , vector<vector<int>> &answer){
        if(sum == target){
            answer.push_back(temp);
            return ;
        }
        if(sum > target || index >= 9){
            return ;
        }
        if(sum + candidates[index] <= target){
            temp.push_back(index);
            back(candidates,index, target ,sum+index,temp, answer);
            temp.pop_back();

        }
        back( index+1, target, sum , temp, answer);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answer;
        vector<int> temp;
        back( 0, k, 0, temp , answer);
        return answer;
    }
};
