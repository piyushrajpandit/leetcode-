

class Solution {
public:
    void recurssion(int n ,int k ,int index,  vector<vector<int>>& answer ,
     vector<int>&temp){
        if(temp.size() == k){
            answer.push_back(temp);
         
            return;
        }
        if(index > n){
            return ;
        }
        
            temp.push_back(index);
            recurssion(n, k, index+1 , answer, temp);
            temp.pop_back();
            recurssion(n, k , index+1, answer, temp);
        

     }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> answer;
        recurssion(n ,k , 1,answer, temp );
        return answer;
    }
};
