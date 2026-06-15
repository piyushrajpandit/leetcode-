/*
LeetCode 416: Partition Equal Subset Sum

Idea:
------
If totalSum is odd, we cannot divide the array into two equal subsets.

If totalSum is even:
    target = totalSum / 2

The problem becomes:

    "Can we find a subset whose sum is equal to target?"

This is the classic Subset Sum Problem.



=========================================================
Approach 1: Tabulation (Bottom-Up DP)
=========================================================

DP State:
----------
dp[index][target]

= true  -> It is possible to form 'target'
           using elements from 0 to index.

= false -> Otherwise.


Base Cases:
------------
1. Sum 0 is always possible.
   dp[i][0] = true

2. Using only the first element:
   if(nums[0] <= target)
       dp[0][nums[0]] = true


Transition:
------------
For each element, we have two choices:

1. Include current element:
   include = dp[index-1][target - nums[index]]

2. Exclude current element:
   exclude = dp[index-1][target]

Therefore,

dp[index][target] = include || exclude


Answer:
---------
dp[n-1][target]


Time Complexity:
-----------------
O(n × target)

Space Complexity:
------------------
O(n × target)



=========================================================
Approach 2: Space Optimization
=========================================================

Observation:
-------------
The current row depends only on the previous row.

dp[index][target]
        ↓
depends only on
dp[index-1][target]

Therefore, instead of storing the entire DP table,
we only store:

next[] -> previous row
curr[] -> current row


Transition:
------------
include = next[target - nums[index]]
exclude = next[target]

curr[target] = include || exclude


After processing one index:

next = curr


Answer:
---------
next[target]


Time Complexity:
-----------------
O(n × target)

Space Complexity:
------------------
O(target)



Flow:
------
Recursion
    ↓
Memoization
    ↓
Tabulation
    ↓
Space Optimization


Key Insight:
-------------
Partition Equal Subset Sum is simply a Subset Sum problem
where the required subset sum is:

    totalSum / 2

If one subset has sum = totalSum/2,
the remaining elements automatically form
the other subset with the same sum.
*/
class Solution {
public:
     bool solve(vector<int>& nums,int total){
              vector<vector<int>> dp(nums.size(), vector<int>(total +1 ,0) );
        for(int i =0; i<nums.size(); i++){
            dp[i][0] = 1; 

        }
        if(nums[0] <= total)
             dp[0][nums[0]] = true;

        for(int index = 1; index< nums.size() ; index++ ){

            for(int target = 0; target <= total; target++){
            
            bool include = 0;
            if(target - nums[index] >=0 )
              include = dp[index-1][target - nums[index]];
        
            //exclude current element 
            bool exclude = dp[index-1][target];

            dp[index][target] = include || exclude ;
             
            }
        }

        return dp[nums.size()-1][total];

      

        

    }
    bool canPartition(vector<int>& nums) {
        
        int totalSum = 0;
        for(int num: nums)
            totalSum += num;

        //if total sum is odd, impossible 
        if(totalSum%2 != 0)
            return false;
        int target = totalSum /2;
  
        return  solve(nums,target);
    }
};

class Solution {
public:
     bool solve(vector<int>& nums,int total){
        vector<int> curr(total +1, 0);
        vector<int> next(total+1, 0);

        curr[0] = 1;
        next[0] = 1; 
       

        
        int N = nums.size();

        for(int index = N-1; index >= 0  ; index--){
            

            for(int target = 0; target <= total; target++){
            
            bool include = 0;
            if(target - nums[index] >=0 )
              include = next[target - nums[index]];
        
            //exclude current element 
            bool exclude = next[target];

            
                 curr[target] = include || exclude;
            

             
            }
            next = curr;

        }

        return next[total];

 
    }
    bool canPartition(vector<int>& nums) {
        
        int totalSum = 0;
        for(int num: nums)
            totalSum += num;

        //if total sum is odd, impossible 
        if(totalSum%2 != 0)
            return false;
        int target = totalSum /2;
  
        return  solve(nums,target);
    }
};
