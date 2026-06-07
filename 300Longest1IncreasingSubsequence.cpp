/*
LeetCode 300 - Longest Increasing Subsequence (LIS)

Problem:
Given an integer array nums, return the length of the
longest strictly increasing subsequence.

Example:
nums = [10,9,2,5,3,7,101,18]

LIS = [2,3,7,101]
Answer = 4

--------------------------------------------------
Approach 1: Recursion
--------------------------------------------------

State:
solve(curr, prev)

curr = current index
prev = previously selected index

Choices:
1. Include nums[curr]
   (only if prev == -1 OR nums[curr] > nums[prev])

2. Exclude nums[curr]

Return maximum of both choices.

Transition:

take =
1 + solve(curr + 1, curr)

notTake =
solve(curr + 1, prev)

answer =
max(take, notTake)

Time Complexity: O(2^n)
Space Complexity: O(n)

--------------------------------------------------
Approach 2: Memoization (Top-Down DP)
--------------------------------------------------

DP State:
dp[curr][prev+1]

Why prev+1?
Because prev can be -1.

Mapping:

prev = -1 → column 0
prev = 0  → column 1
prev = 1  → column 2
...

Store result of every state to avoid recomputation.

Time Complexity: O(n²)
Space Complexity: O(n²) + O(n recursion stack)

--------------------------------------------------
Approach 3: Tabulation (Bottom-Up DP)
--------------------------------------------------

DP State:
dp[curr][prev+1]

Meaning:
Length of LIS starting from curr
when previous selected index is prev.

Build table from back to front.

Transition:

take =
1 + dp[curr+1][curr+1]

notTake =
dp[curr+1][prev+1]

dp[curr][prev+1] =
max(take, notTake)

Answer:
dp[0][0]

Time Complexity: O(n²)
Space Complexity: O(n²)

--------------------------------------------------
Approach 4: Space Optimization
--------------------------------------------------

Observation:

Current row only depends on next row.

So instead of storing the entire DP table:

dp[curr][*]

Store only:

currRow
nextRow

Transition:

take =
1 + nextRow[curr+1]

notTake =
nextRow[prev+1]

currRow[prev+1] =
max(take, notTake)

After processing:

nextRow = currRow

Answer:
nextRow[0]

Time Complexity: O(n²)
Space Complexity: O(n)

--------------------------------------------------
Key Insight
--------------------------------------------------

For every element we have two choices:

1. Take it into the subsequence
2. Skip it

The DP state tracks:
- Current position
- Previous chosen element

This converts an exponential recursion into an O(n²) solution.

--------------------------------------------------
Further Optimization
--------------------------------------------------

There is an optimal Binary Search solution
(Patience Sorting Technique).

Time Complexity: O(n log n)
Space Complexity: O(n)

This is the most efficient solution for
LeetCode 300 and is usually expected in interviews.
*/

class Solution {
public:

    int solve(vector<int>& nums, int n, int curr, int prev) {

        // base case
        if(curr == n) {
            return 0;
        }

        int take = 0;

        if(prev == -1 || nums[curr] > nums[prev]) {
            take = 1 + solve(nums, n, curr + 1, curr);
        }

        int notTake = solve(nums, n, curr + 1, prev);

        return max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        return solve(nums, n, 0, -1);
    }
};


class Solution {
public:
    int solve(vector<int> &a, int n, int curr, int prev,vector<vector<int> > &dp){
        //base case 
        if(curr == n){
            return 0;
        }
        if(dp[curr][prev+1]!= -1)
            return dp[curr][prev+1];
        //include 
        int take =0;
        if(prev == -1 || a[curr] > a[prev])
            take = 1 + solve(a, n, curr+1, curr,dp);

        //exclude 
        int notTake = 0 + solve(a, n, curr+ 1 , prev,dp);

        return dp[curr][prev+1] =  max(take , notTake);

    }
    int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
        vector<vector<int> > dp(n, vector<int> (n+1, -1));

       
        return solve(nums, n, 0, -1,dp);

    }
};

class Solution {
public:
    int solve(vector<int> &a, int n){

       
        vector<vector<int> > dp(n+1, vector<int> (n+1, 0));
        
        for(int curr = n-1; curr >= 0 ; curr--){
            for(int prev = curr -1 ; prev>= -1; prev--){
                   
        int take =0;
        if(prev == -1 || a[curr] > a[prev])
            take = 1 + dp[curr+1][curr+1];

        //exclude 
        int notTake = 0 + dp[curr+1][prev+1];

         dp[curr][prev+1] =  max(take , notTake);
            }
        }
        return dp[0][0];
    
    }
    int lengthOfLIS(vector<int>& nums) {
       
           int n = nums.size();
       
        return solve(nums, n);

    }
};


class Solution {
public:
    int solve(vector<int> &a, int n){

       
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr = n-1; curr >= 0 ; curr--){
            for(int prev = curr -1 ; prev>= -1; prev--){
                   
        int take =0;
        if(prev == -1 || a[curr] > a[prev])
            take = 1 + nextRow[curr+1];

        //exclude 
        int notTake = 0 + nextRow[prev+1];

         currRow[prev+1] =  max(take , notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    
    }
    int lengthOfLIS(vector<int>& nums) {
       
           int n = nums.size();
       
        return solve(nums, n);

    }
};
