//same bfs is used here 
// easy code if you remmenber bfs my last few question are related to this so it is easy 


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        queue<pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        
        int island = 0;
        vector<pair<int, int >> moves = {
                {0,1},
                {1,0},
                {0,-1},
                {-1,0}
        };
       
        
            for(int i =0 ; i< rows; i++){
                for(int j =0; j< cols; j++){
                  
                    if( visited[i][j] == 0 && grid[i][j] == '1'){
                        q.push({i,j});
                        visited[i][j] = 1;
                        island++;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            for(auto move: moves){
                int nr = r + move.first;
                int nc = c + move.second;
                if(nr >= 0 && nr < rows && 
                   nc >= 0 && nc < cols &&
                   grid[nr][nc] == '1' && visited[nr][nc]==0 ){
                        visited[nr][nc] = 1;
                        q.push({nr,nc});

                   }
                }
            }
        }
        }
            
        }
        return island;

    }
};
