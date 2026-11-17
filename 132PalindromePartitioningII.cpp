class Solution {
public:
   bool isPalindrom(string s, int i , int j){
    while(i <=j){
        if(s[i] != s[j]){
            
            return false;
        }
        i++;
        j--;
    }
    return true;
   }
    int solve(string &s ,int i ){
        
        if(i == s.size() ){
            return -1;
        }
        int ans = INT_MAX;

       for(int j= i ; j< s.size() ;j++){
        if(isPalindrom(s,i,j)){
            ans = min(ans, 1+ solve(s,j+1));
        }
       }
        return ans;
    }
    int minCut(string s) {
        return solve(s,0);
    }
};

class Solution {
public:
   bool isPalindrom(string& s, int i , int j){
    while(i <=j){
        if(s[i] != s[j]){
            
            return false;
        }
        i++;
        j--;
    }
    return true;
   }
    int solve(string &s ,int i, vector<int>& dp ){
        
        if(i == s.size() ){
            return -1;
        }
        int ans = INT_MAX;
        if(dp[i] != -2){
            return dp[i];
        }
       for(int j= i ; j< s.size() ;j++){
        if(isPalindrom(s,i,j)){
            ans = min(ans, 1+ solve(s,j+1,dp));
           
        }
       }
        return  dp[i] = ans;;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-2);
        //dp[i] minimium number of cut needed for stirng at i th position
        return solve(s,0,dp);
    }
};
