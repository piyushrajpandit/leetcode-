


class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
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
                  
                    if( visited[i][j] == 0 && grid[i][j] == 0){
                        q.push({i,j});
                        visited[i][j] = 1;


                        bool closed = true;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            if(r ==0 || c == 0 || r == rows -1 || c == cols -1){
                    closed = false;
                }
            for(auto move: moves){
                int nr = r + move.first;
                int nc = c + move.second;
               
                if(nr >= 0 && nr < rows && 
                   nc >= 0 && nc < cols &&
                   grid[nr][nc] == 0 && visited[nr][nc]==0 ){
                        visited[nr][nc] = 1;
                        q.push({nr,nc});

                   }
                }
         
            }
        if(closed){
                island++;
        }
        }
        }
            
        }
        return island;

    }
};
