Backtracking Recursion Tree:
/*
back(nums, used, 0, 4, 0, 5)
|
|-- Choose 5
|   |
|   |-- sum == target (5)
|       |
|       |-- back(nums, used, 0, 3, 0, 5)
|           |
|           |-- Choose 4
|           |   |
|           |   |-- Choose 1
|           |       |
|           |       |-- sum == target (5)
|           |           |
|           |           |-- back(nums, used, 0, 2, 0, 5)
|           |               |
|           |               |-- Choose 3
|           |               |   |
|           |               |   |-- Choose 2
|           |               |       |
|           |               |       |-- sum == target (5)
|           |               |           |
|           |               |           |-- back(nums, used, 0, 1, 0, 5)
|           |               |               |
|           |               |               |-- k == 1
|           |               |                   |
|           |               |                   |-- return true
|
|-- Final Result: true

Subsets formed:
{5}, {4, 1}, {3, 2}, {3, 2}
*/
Time Complexity: Exponential in the worst case.
Space Complexity: O(n) for recursion and the used array.

class Solution {
public:
   
    bool back(vector<int>& nums,vector<bool>& used,  int index,int k , int sum , int target){
        if(k==1){
            return true;
        }
        if(sum == target){
            
            return back(nums,used, 0, k-1, 0, target);
        }
        for(int i = index ; i< nums.size() ;i++){
            if(used[i] || sum + nums[i] > target){
                continue;
            }
            used[i] = true;
            if(back(nums, used,i+1 , k, sum+ nums[i] , target)){
                return true;
            }
            used[i] = false;
            if(sum == 0 ) return false;
            if(sum + nums[i] == target ) return false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {   
        int sum = 0;
        for(int i =0 ; i< nums.size();i++){
            sum += nums[i];
        }
        if(sum % k != 0){
            return false;
        }
        int target = sum/k;
        sort(nums.begin(), nums.end());
        if(nums[0] > target )return false;
        vector<bool> used(nums.size(), false);
      
        
        
        return back(nums, used, 0, k, 0, target);
    }
};
