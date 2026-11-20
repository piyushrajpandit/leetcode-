class Solution {
public:
    int dp[601][101][101];

    int  solve(vector<string>& strs, int m , int n, int index , int count1, int count0  ){

        if(index == strs.size()){
            return 0;
        }

        if(dp[index][count0][count1] != -1)
            return dp[index][count0][count1];
       
       
        int ones = 0 ;
        int zeros= 0;

        for(int i =0 ; i< strs[index].size(); i++){
            if(strs[index][i] == '0'){
                zeros++;
            }
            else{
                ones++;
            }
        }
        //case 1 take it 
        int take = 0;
        if(count0 + zeros <= m && count1 +ones <= n){
            take = 1 + solve(strs,m,n , index+1, count1+ ones, count0 + zeros);

        }
        //igonore it 
        int ignore = solve(strs,m,n, index+1, count1, count0);
        return dp[index][count0][count1] = max({take , ignore});
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return   solve( strs, m , n,0 , 0, 0  );
    }
};
