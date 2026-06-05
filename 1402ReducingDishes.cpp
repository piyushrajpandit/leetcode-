/*
LeetCode 1402 - Reducing Dishes

Problem:
Given an array satisfaction[], choose any subset of dishes and arrange
their cooking order to maximize the Like-Time Coefficient.

Like-Time Coefficient:
Σ (satisfaction[i] * time)

Approach:
1. Sort the satisfaction array.
2. For each dish, we have two choices:
   - Include the current dish:
     satisfaction[index] * (time + 1)
     + solve(index + 1, time + 1)
   - Exclude the current dish:
     solve(index + 1, time)
3. Take the maximum of both choices.

DP State:
dp[index][time]
= Maximum satisfaction obtainable starting from index
  when current cooking time is time.

Transition:
Include:
satisfaction[index] * (time + 1)
+ dp[index + 1][time + 1]

Exclude:
dp[index + 1][time]

Base Case:
When index == n, no dishes remain.
Return 0.

Complexities:

1. Recursive Solution
   Time Complexity : O(2^n)
   Space Complexity: O(n)

2. Memoization (Top-Down DP)
   Time Complexity : O(n^2)
   Space Complexity: O(n^2) + O(n)

3. Tabulation (Bottom-Up DP)
   Time Complexity : O(n^2)
   Space Complexity: O(n^2)

4. Space Optimized DP
   Time Complexity : O(n^2)
   Space Complexity: O(n)

Key Insight:
Sorting is essential. Sometimes including a small negative satisfaction
dish increases the final answer because it shifts larger positive dishes
to later time slots, increasing their contribution.
*/


class Solution {
public:
    int solve(vector<int> & satisfaction , int index, int time){
         if(index == satisfaction.size())
            return 0;
        int include = satisfaction[index] *(time +1) + solve(satisfaction ,index +1, time+1);
        int exclude = 0 + solve(satisfaction , index+1, time);

        return max(include ,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
       //sort the vector
       sort(satisfaction.begin(), satisfaction.end());
       return solve(satisfaction, 0, 0);
    }
};

class Solution {
public:
    int solve(vector<int> & satisfaction , int index, int time,  vector<vector<int>> &dp){
         if(index == satisfaction.size())
            return 0;

        if(dp[index][time]!= -1 )
            return dp[index][time];

        int include = satisfaction[index] *(time +1) + solve(satisfaction ,index +1, time+1,dp);
        int exclude = 0 + solve(satisfaction , index+1, time,dp);

        return dp[index][time] =  max(include ,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
       //sort the vector
       sort(satisfaction.begin(), satisfaction.end());
       int n = satisfaction.size();
       vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
       return solve(satisfaction ,0, 0 , dp);
    }
};


class Solution {
public:



    int solve(vector<int> & satisfaction ){
         int n = satisfaction.size();
          vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
            for(int index = n-1  ; index >= 0 ; index--){
                for(int time = index; time >= 0; time--){

                int include = satisfaction[index] *(time +1) + dp[index+1][time+1];
                int exclude = 0 + dp[index +1][time];

                dp[index][time]=  max(include ,exclude);
                }
            }
            return dp[0][0];

    }
    int maxSatisfaction(vector<int>& satisfaction) {
      sort(satisfaction.begin(), satisfaction.end());
        
       return solve(satisfaction);
    }
};


class Solution {
public:



    int solve(vector<int> & satisfaction ){
         int n = satisfaction.size();
          vector<int> curr(n+1, 0);
          vector<int> next(n+1, 0);
            for(int index = n-1  ; index >= 0 ; index--){
                for(int time = index; time >= 0; time--){

                int include = satisfaction[index] *(time +1) + next[time+1];
                int exclude = 0 + next[time];

                curr[time]=  max(include ,exclude);
                }
                next = curr;
            }
            return next[0];

    }
    int maxSatisfaction(vector<int>& satisfaction) {
      sort(satisfaction.begin(), satisfaction.end());
        
       return solve(satisfaction);
    }
};
