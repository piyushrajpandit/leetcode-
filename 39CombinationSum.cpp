//   temp.pop_back();
this is most important line which i always forget problem is here once we move forward then when we come back and 
remove the element and try different combinations 


class Solution {
public:

    void back(vector<int>& candidates ,int index ,int target,int sum,vector<int>& temp,vector<vector<int>> & answer){
        if(sum == target){
            answer.push_back(temp);
            return ;
        }
       
        if(sum > target || index >= candidates.size()){
            return ;
        }
        if(sum + candidates[index] <= target){
            temp.push_back(candidates[index]);
            back(candidates, index, target, sum+ candidates[index] , temp ,answer);
            temp.pop_back();
        }
        back(candidates, index+1, target, sum , temp , answer);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> temp;

         back(candidates, 0, target,0,temp, answer );
     
        
        return answer;
    }

};
