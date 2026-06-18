class Solution {
public:
    int solve(int index , int diff ,vector<int>& A){
        //backward check 
        if(index <0)
            return 0;
        int ans = 0;
        for(int j = index-1; j>=0; j--){
            if(A[index]- A[j] == diff){
                ans = max(ans, 1+solve(j,diff, A));

            }
        }
        return ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
            return n;
        int ans = 0 ;
        for(int i =0; i<n; i++){
            for(int j = i+1; j<n; j++){
                ans = max(ans, 2+solve(i,nums[j]-nums[i], nums));
            }
        }
        return ans;
    }
};
class Solution {
public:
    int solve(int index , int diff ,vector<int>& A,unordered_map<int , int>dp[]){
        //backward check 
        if(index <0)
            return 0;

        if(dp[index].count(diff))
            return dp[index][diff];

        int ans = 0;
        for(int j = index-1; j>=0; j--){
            if(A[index]- A[j] == diff){
                ans = max(ans, 1+solve(j,diff, A,dp));

            }
        }
        return dp[index][diff] =  ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
            return n;
        int ans = 0 ;
        unordered_map<int , int>dp[n+1];
        for(int i =0; i<n; i++){
            for(int j = i+1; j<n; j++){
                ans = max(ans, 2+solve(i,nums[j]-nums[i], nums,dp));
            }
        }
        return ans;
    }
};
class Solution {
public:
  
  
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
            return n;
        int ans = 0 ;
        unordered_map<int , int>dp[n+1];
        for(int i =1; i<n; i++){
            for(int j = 0; j<i; j++){
                int diff = nums[i] - nums[j];
                int cnt = 1; 
                //check if answer already present 
                if(dp[j].count(diff))
                    cnt = dp[j][diff];
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};
