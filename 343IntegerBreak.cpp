
// this is the code 
class Solution {
public:
    int solve(int n,vector<int> &dp){
        
        if(n==1)
            return 1;
        int maxi = INT_MIN;

        if(dp[n]!= -1)
            return dp[n];

         
        for(int j=1 ; j<n ; j++){
            int noBreak= j* (n-j);
            
            int furtherBreak = j* solve(n-j,dp);
            
            maxi = max(maxi, max(noBreak, furtherBreak));
        }
        dp[n] = maxi;
        
        return dp[n];

       
        
        
        
    }
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);

        return solve(n,dp);
    }
};



//recurrsion 

class Solution {
public:
    int solve(int n){
        
        if(n==1)
            return 1;
        int maxi = INT_MIN;

         
        for(int j=1 ; j<n ; j++){
            int noBreak= j* (n-j);
            int furtherBreak = j* solve(n-j);
            
            maxi = max(maxi, max(noBreak, furtherBreak));
        }
        
        return maxi;

       
        
        
        
    }
    int integerBreak(int n) {
        return solve(n);
    }
};
//this is the code that is not totally corect but written by me 
class Solution {
public:
    int solve(int n,int k){
        
        vector<int> ele(k, INT_MIN);
        //stop condition 
         if(k>n)
            return INT_MIN;
        //fill first k-1 element 
        for(int i=0 ; i< k-1 ; i++){
            ele[i] = n/k;
        }
        if(n%k == 0 ){
            ele[k-1] = n/k;
        }
        else
        ele[k-1] = n%k + n/k;

        //calcution of product 
        int ans = 1;
        for(int i =0 ; i <k ; i++){
            ans*= ele[i];

        }
       
        int result = solve(n,k+1);
        result = max(result, ans);
        return result;
        
        
        
    }
    int integerBreak(int n) {
        return solve(n,2);
    }
};
