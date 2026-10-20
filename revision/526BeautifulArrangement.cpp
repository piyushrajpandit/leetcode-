// the question is 

/*
Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

  */
/*
i have written a code from by makeing a vector of nums and all possible premutation and 
then check each vector by condition but it give runtime error 
*/
class Solution {
public:
    
    void solve(vector<int>nums, vector<vector<int>>& ans, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int j = index ; j< nums.size() ;j++){
            swap(nums[index], nums[j]);
            solve(nums,ans, index+1);
            swap(nums[index] , nums[j]);
        }

    }
    int count = 0;
    void backtrack(vector<vector<int>> ans, int index,int temp){
        if(index == temp){
            return;
        }
        int n = ans[index].size();
        int i=0 ;
        while(i < n){
            int pos = i+1;
            int val = ans[index][i];
            if(val % pos == 0 || pos % val == 0){
                i++;
            }
            else{
                break;
            }
        }
        if(i == n){
            count++;
        }
        backtrack(ans, index+1,temp);
        
    }
    int countArrangement(int n) {
        vector<int> nums(n);
        for(int i =0 ; i< n; i++){
            nums[i] = i+1; 
        }
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        int temp = ans.size();
        backtrack(ans, index, temp);
        return count;
    }
};




// so chat gpt suggested 
// hope when second time we come to this problem we revise it better and understand it better 

class Solution {
public:
    int count = 0;

    void solve(int n, int pos, vector<bool>& used) {
        if (pos > n) {
            count++;
            return;
        }

        for (int num = 1; num <= n; num++) {
            if (!used[num] &&
                (num % pos == 0 || pos % num == 0)) {

                used[num] = true;
                solve(n, pos + 1, used);
                used[num] = false;
            }
        }
    }

    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        count = 0;
        solve(n, 1, used);
        return count;
    }
};
