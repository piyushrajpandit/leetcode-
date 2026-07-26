/*
default i was using dfs but that wont work  here we have to use bfs because it is good for this 
enter things in queue and mark them visited traval each step and add them to queue 

  */
class Solution {
public:

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // move uppwad 
        int row  = maze.size();
        int col = maze[0].size();

        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});

        maze[entrance[0]][entrance[1]] = '+';

        int dRow[] = {-1,1,0,0};
        int dCol[] = {0,0,1,-1};

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int r = curr[0];
            int c = curr[1];
            int steps = curr[2];

            for(int i=0 ;i< 4; i++){
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];

                if(nRow >= 0 && nRow < row &&  nCol >= 0 && nCol < col && maze[nRow][nCol] == '.'){
                    if(nRow == 0 || nRow == row-1 || nCol == 0 || nCol == col-1){
                        return steps+1;
                    }
                    maze[nRow][nCol] = '+';
                    q.push({nRow , nCol , steps+1});
                }
            }
        }
     
       return -1; 
    }
};
