class Solution {
public:
    int count = 0;
    int total= 0;
    void back(vector<vector<int>> & grid, int row, int col,vector<pair<int,int>> temp){
        int rows = grid.size();
        int cols = grid[0].size();
        if(row < 0|| row >= rows || col <0 || col >= cols)
            return ;
        if(grid[row][col]== -1){
            return ;
        }
        
        if(grid[row][col] == 2 ){
           if((int)temp.size() + 1 == total)
                count++;
            return;
        }
        int original = grid[row][col];
        grid[row][col] = -1;
        temp.push_back({row, col});
        back(grid, row+1,col , temp);
        back(grid, row,col-1 , temp);
        back(grid, row-1,col , temp);
        back(grid, row,col+1 , temp);
        grid[row][col]= original;
        temp.pop_back();

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // make some thing to mark visited 
        int row = 0;
        int col = 0;
        for(int i =0 ; i< rows ; i++){
            for(int j =0 ; j< cols ; j++){
                if(grid[i][j] != -1)
                        total++;
                if(grid[i][j]== 1){
                    row = i;
                    col = j;
                }
            }
        }
        vector<pair<int,int>> temp;
        back(grid,row, col , temp);
        return count;
    }
};
