// #apprach 
// here you have to do the folling things 
// first make visited 

//         int rows = grid.size();
//         int cols = grid[0].size();

//         vector<vector<bool>> visited(rows, vector<bool>(cols, false));

// like this and if its 0 skip it and if its 1 call dfs 


// now in dfs 
// i<0 or j<0 i>= rows j>= cols
// return 0
// if gird[i][j] ==0 
// then also return 0 
//   if visited is true then also return 0 
//   else mark visited and call 
// dfs in all the direction 

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j,vector<vector<bool>>& visited){
       int rows = grid.size();
       int cols = grid[0].size();
     

       //boundary check
       if(i<0 || j <0 || i >= rows || j>= cols )
        return 0;
        //water cell
        if(grid[i][j] == 0 )
            return 0 ;

        //already visited 
        if(visited[i][j])
            return 0;
        
        visited[i][j] = true;
        int count =1 ;
                // 4 directions
        count += dfs(grid, i + 1, j, visited);
        count += dfs(grid, i - 1, j, visited);
        count += dfs(grid, i, j + 1, visited);
        count += dfs(grid, i, j - 1, visited);

        return count;


        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int maxarea=0;
        for(int i =0 ; i< grid.size();i++){
            for(int j=0 ; j< grid[0].size();j++){
                if(!visited[i][j]){
                    if(grid[i][j]==0){
                        continue;
                    }
                    else{
                        int area = dfs(grid,i,j,visited);
                        maxarea = max(area, maxarea);
                    }
                }
            }
        }
        return  maxarea;
        
    }
};
