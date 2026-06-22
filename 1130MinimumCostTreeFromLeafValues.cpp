/*
Approach: DP + Memoization

1. A non-leaf node value is equal to:
      (maximum leaf in left subtree) * (maximum leaf in right subtree)

2. Precompute the maximum element for every subarray [i...j]
   and store it in 'maxi' to avoid recomputing maximums repeatedly.

3. Define:
      solve(left, right)
   = minimum cost to construct a tree using leaves from
     index left to right.

4. Base Case:
      left == right
      => only one leaf node, so cost = 0.

5. For every possible partition point 'i':
      [left...i] | [i+1...right]

   Cost =
      max(left part) * max(right part)
      + cost(left subtree)
      + cost(right subtree)

6. Take the minimum cost among all possible partitions.

7. Use DP memoization (dp[left][right]) to store already
   computed intervals and avoid repeated calculations.

Time Complexity: O(N^3)
   - O(N^2) states
   - O(N) partitions for each state

Space Complexity: O(N^2)
   - DP table
   - Maximum-value lookup table
*/
class Solution {
public:
    int solve(vector<int>& arr, map<pair<int ,int>,int>&maxi , int left, int right){
        //leaf node 
        if(left == right)
            return 0;
        int ans = INT_MAX;
        for(int i= left ; i< right; i++){
            ans = min(ans, maxi[{left ,i}]*maxi[{i+1, right}]+ solve(arr, maxi, left ,i)+ solve(arr, maxi ,i+1, right));
        }
        return ans; 

    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>, int >maxi;
        for(int i =0 ; i<arr.size();i++){
            maxi[{i,i}] = arr[i];
            for(int j = i+1; j< arr.size(); j++){
                maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);

            }
        }
     return solve(arr, maxi,0, arr.size()-1);
    }
};

class Solution {
public:
    int solve(vector<int>& arr, map<pair<int ,int>,int>&maxi , int left, int right, vector<vector<int>> &dp){
        //leaf node 
        if(left == right)
            return 0;

        if(dp[left][right]!= -1)
            return dp[left][right];
        int ans = INT_MAX;
        for(int i= left ; i< right; i++){
            ans = min(ans, maxi[{left ,i}]*maxi[{i+1, right}]+ solve(arr, maxi, left ,i,dp)+ solve(arr, maxi ,i+1, right,dp));
        }
        return dp[left][right]=  ans; 

    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>, int >maxi;
        int n= arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i =0 ; i<arr.size();i++){
            maxi[{i,i}] = arr[i];
            for(int j = i+1; j< arr.size(); j++){
                maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);

            }
        }
     return solve(arr, maxi,0, arr.size()-1,dp);
    }
};
