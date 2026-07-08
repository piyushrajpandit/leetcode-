/*
Wildcard Matching (DP Summary)

1. Recursive
   State:
      solve(i, j) -> whether str[0...i] matches pattern[0...j]

   Base Cases:
      i < 0 && j < 0  -> true
      i >= 0 && j < 0 -> false
      i < 0 && j >= 0 -> remaining pattern must contain only '*'

   Transitions:
      Match / '?':
         solve(i-1, j-1)

      '*':
         solve(i-1, j)   -> '*' matches one or more characters
         solve(i, j-1)   -> '*' matches zero characters

      Else:
         false

   Time: Exponential
   Space: O(n+m)


2. Memoization
   - Store answer of each (i,j) in dp[][].
   - Same transitions as recursion.
   - Avoid recomputing states.

   Time: O(n*m)
   Space: O(n*m)


3. One-Based Indexing
   State:
      solve(i,j) -> first i characters of string and first j characters of pattern.

   Base Cases:
      i==0 && j==0 -> true
      i>0 && j==0  -> false
      i==0 && j>0  -> first j pattern characters must all be '*'

   Advantage:
      No negative indexing.
      Easier conversion to tabulation.


4. Tabulation
   DP State:
      dp[i][j] = first i characters of string match first j characters of pattern.

   Initialization:
      dp[0][0] = true
      dp[0][j] = true only if first j pattern characters are all '*'

   Transition:
      Match / '?':
         dp[i][j] = dp[i-1][j-1]

      '*':
         dp[i][j] = dp[i-1][j] || dp[i][j-1]

      Else:
         dp[i][j] = false

   Time: O(n*m)
   Space: O(n*m)


5. Space Optimization
   Observation:
      Current row depends only on previous row and current row.

   Use:
      prev[], curr[]

   Transition:
      Match / '?':
         curr[j] = prev[j-1]

      '*':
         curr[j] = prev[j] || curr[j-1]

      After each row:
         prev = curr

   Time: O(n*m)
   Space: O(m)

------------------------------------------------------------
Key Formula:
Match / '?':
   dp[i][j] = dp[i-1][j-1]

'*':
   dp[i][j] = dp[i-1][j] || dp[i][j-1]

Meaning of '*':
   dp[i-1][j] -> '*' matches one or more characters.
   dp[i][j-1] -> '*' matches zero characters.
------------------------------------------------------------
*/

class Solution {
public:
    bool solve(string str, string pattern , int i, int j){
        //base case 
        if(i <0 && j< 0)
            return true; 
        if(i>=0 && j<0)
            return false;
        if(i< 0 && j>=0 ){
            for(int k =0 ; k<= j; k++){
                if(pattern[k] != '*'){
                    return false;
                }
            }
            return true;
        }
        //match 
        if(str[i] == pattern[j] || pattern[j] =='?'){
            return solve(str, pattern , i-1, j-1);
        }
        else if(pattern[j] =='*'){
            return (solve(str, pattern , i-1, j )|| solve(str, pattern , i, j-1));
        }
        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        return solve(s,p , s.length() -1 , p.length()-1 );
    }
};

class Solution {
public:
    bool solve(string &str, string& pattern , int i, int j, vector<vector<int>>& dp){
        //base case 
        if(i <0 && j< 0)
            return true; 
        if(i>=0 && j<0)
            return false;
        if(i< 0 && j>=0 ){
            for(int k =0 ; k<= j; k++){
                if(pattern[k] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j]!= -1)
            return dp[i][j];
        //match 
        if(str[i] == pattern[j] || pattern[j] =='?'){
            return  dp[i][j] = solve(str, pattern , i-1, j-1, dp);
        }
        else if(pattern[j] =='*'){
            return dp[i][j] = (solve(str, pattern , i-1, j,dp )|| solve(str, pattern , i, j-1,dp));
        }
        else{
            return dp[i][j] = false;
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return solve(s,p , s.length() -1 , p.length()-1,dp );
    }
};

//one based indexing 
class Solution {
public:
    bool solve(string &str, string& pattern , int i, int j, vector<vector<int>>& dp){
        //base case 
        if(i ==0 && j== 0)
            return true; 
        if(i>0 && j==0)
            return false;
        if(i== 0 && j>0 ){
            for(int k =1 ; k<= j; k++){
                if(pattern[k-1] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j]!= -1)
            return dp[i][j];
        //match 
        if(str[i-1] == pattern[j-1] || pattern[j-1] =='?'){
            return  dp[i][j] = solve(str, pattern , i-1, j-1, dp);
        }
        else if(pattern[j-1] =='*'){
            return dp[i][j] = (solve(str, pattern , i-1, j,dp )|| solve(str, pattern , i, j-1,dp));
        }
        else{
            return dp[i][j] = false;
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, -1));
        return solve(s,p , s.length()  , p.length(),dp );
    }
};

class Solution {
public:
    bool solve(string &str, string& pattern ){
      vector<vector<int>> dp(str.length()+1, vector<int>(pattern.length()+1, 0));
    
    dp[0][0] = true;
    for(int j= 1; j <= pattern.length(); j++){
        bool flag = true;
        for(int k = 1; k<= j; k++ ){
            if(pattern[k-1] != '*'){
                flag = false;
                break;
        }
        }

        dp[0][j] = flag ;
    }
    for(int i = 1 ; i<= str.length() ; i++){
        for(int j =1; j<= pattern.length(); j++){
                    if(str[i-1] == pattern[j-1] || pattern[j-1] =='?'){
                         dp[i][j] =dp[i-1][j-1];
                    }
                    else if(pattern[j-1] =='*'){
                        dp[i][j] = (dp[i-1][j]|| dp[i][j-1]);
                    }
                    else{
                         dp[i][j] = false;
                    }
        }
    }
     
      return dp[str.length()][pattern.length()];
    }
    bool isMatch(string s, string p) {
       
        return solve(s,p  );
    }
};

class Solution {
public:
    bool solve(string &str, string& pattern ){
    vector<int> prev(pattern.length()+1, 0);
    vector<int> curr(pattern.length()+1, 0);

    prev[0] = true;
    for(int j= 1; j <= pattern.length(); j++){
        bool flag = true;
        for(int k = 1; k<= j; k++ ){
            if(pattern[k-1] != '*'){
                flag = false;
                break;
        }
        }

        prev[j] = flag ;
    }
    for(int i = 1 ; i<= str.length() ; i++){
        for(int j =1; j<= pattern.length(); j++){
                    if(str[i-1] == pattern[j-1] || pattern[j-1] =='?'){
                         curr[j] =prev[j-1];
                    }
                    else if(pattern[j-1] =='*'){
                        curr[j] = (prev[j]|| curr[j-1]);
                    }
                    else{
                         curr[j] = false;
                    }
        }
        prev = curr;
    }
     
      return prev[pattern.length()];
    }
    bool isMatch(string s, string p) {
       
        return solve(s,p  );
    }
};
