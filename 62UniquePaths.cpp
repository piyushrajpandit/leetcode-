class Solution {
public:
    
    int uniquePaths(int m, int n) {
        int count =0;
        vector<pair<int ,int>> moves = {
            {1,0},
            {0,1},
          
        };
        queue<pair<int, int>> q;
        q.push({0,0});
        while(!q.empty()){

            auto temp = q.front();
            q.pop();

            int row = temp.first;
            int col = temp.second;
            if(row == m-1 && col == n-1){
                count++;
                continue;
            }
            for(auto move : moves){
                int newRow = row + move.first;
                int newCol = col + move.second;
                if(newRow < m && newCol <n)
                    q.push({newRow, newCol});
            }
        }
        return count;
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
