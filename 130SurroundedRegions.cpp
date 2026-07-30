/*

# Surrounded Regions (LeetCode 130) - Summary

### Key Idea

* A region of `'O'` should be changed to `'X'` **only if it is completely surrounded by `'X'`**.
* Any `'O'` connected to the **border** can never be surrounded, so it must remain `'O'`.

### Approach (BFS/DFS)

1. Traverse all **border cells**.
2. If a border cell contains `'O'`, start **BFS/DFS** from it.
3. Mark every connected `'O'` as `'#'` (safe).
4. After all traversals:

   * Change every remaining `'O'` → `'X'` (surrounded region).
   * Change every `'#'` → `'O'` (restore safe cells).

### Why Start from the Border?

* Border `'O'` cells and all `'O'` connected to them **cannot** be captured.
* Instead of finding surrounded regions, mark all **non-surrounded** regions first.

### BFS Steps

* Push the border `'O'` into the queue.
* Mark it as `'#'`.
* Visit its 4-directional neighbors.
* If a neighbor is inside the grid and is `'O'`, mark it `'#'` and push it into the queue.

### Common Mistakes

* Starting BFS from **every** `'O'` instead of only border `'O'`.
* Converting `'O'` to `'X'` during BFS.
* Forgetting the final traversal to restore `'#'` back to `'O'`.
* Iterating only until `rows - 1` or `cols - 1`, which skips the last row/column.
* Accessing neighbors before checking boundary conditions.

### Time Complexity

* **O(m × n)**

### Space Complexity

* **O(m × n)** in the worst case (BFS queue or DFS recursion).


  */



class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return ;
        queue<pair<int, int>> q; 
        int rows = board.size();
        int cols = board[0].size();
        
    
     

        vector<pair<int, int>> moves = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };
        for(int i=0; i< rows; i++){
            for(int j=0; j < cols; j++){
                if(  board[i][j] == 'O'
                && (i ==0 || i == rows-1 || j==0 || j == cols -1 )){
                    q.push({i,j});
                
                    board[i][j] = '#';

                while(!q.empty()){
                    auto curr = q.front();
                    q.pop();
                    int r = curr.first;
                    int c = curr.second;
                    for(auto move: moves){
                        int nr = r + move.first;
                        int nc = c + move.second;
                        
                        if(nr >= 0 && nr < rows && nc >= 0 && nc < cols  && board[nr][nc] == 'O' ){
                          
                            board[nr][nc] = '#';
                            q.push({nr,nc});
                        }
                       

                    }
                }
                }
            }
        }
        for(int i=0 ; i<rows  ;i++){
            for(int j=0 ; j< cols ;j++){
                    if(board[i][j] == 'O')
                    board[i][j] = 'X';
                    else if(board[i][j] == '#')
                    board[i][j] = 'O';
                   

            }
        }
    }
};
