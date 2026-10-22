class Solution {
public:
    int answer =0;
    void gold(vector<vector<int>> & grid, int row, int col ,int sum){
        int rows = grid.size();
        int cols = grid[0].size();
        if(row < 0 || row >= rows || col < 0|| col >= cols)
            return;
        if(grid[row][col] == 0){
            return;
        }
        sum += grid[row][col];
        int original = grid[row][col];
        answer  = max(sum , answer);
        grid[row][col] = 0;
        gold(grid, row + 1, col ,sum);
        gold(grid, row, col -1, sum);
        gold(grid, row-1 , col, sum);
        gold(grid, row, col+1, sum);
        grid[row][col] = original;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int cols = grid[0].size();
        int rows = grid.size();
        for(int i =0; i< rows; i++){
            for(int j =0; j< cols; j++){
                if(grid[i][j] != 0){
                    gold(grid, i,j,0);
                }
            }
        }
 
    
        return answer;

    }
};
