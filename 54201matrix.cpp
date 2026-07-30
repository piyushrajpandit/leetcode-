/*01 Matrix (Multi-Source BFS) Summary

Goal: Find the shortest distance from every cell containing 1 to the nearest cell containing 0.
Step 1: If the matrix is empty, return an empty matrix.
Step 2: Create a queue for BFS.
Step 3: Traverse the matrix:
If a cell contains 0, push its coordinates into the queue.
If a cell contains 1, replace it with INT_MAX to represent an unknown distance.
Step 4: Define the four possible movement directions:
Right (0,1)
Down (1,0)
Left (0,-1)
Up (-1,0)
Step 5: Perform Multi-Source BFS:
While the queue is not empty:
Remove the front cell (r, c).
Visit all four neighboring cells.
Check if the neighbor is inside the matrix.
If mat[nr][nc] > mat[r][c] + 1, update:
mat[nr][nc] = mat[r][c] + 1
Push (nr, nc) into the queue.
Step 6: Continue until the queue becomes empty.
Step 7: Return the updated matrix.

Key Idea: Start BFS from all 0s simultaneously instead of running BFS from every 1. Since BFS explores level by level, the first distance assigned to each cell is its shortest distance to a 0.

Time Complexity: O(rows × cols)

Space Complexity: O(rows × cols)
*/
#include <climits>
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if(mat.empty())
            return {};
        queue<pair<int , int> > q; 
        int rows = mat.size();
        int cols = mat[0].size();

        vector<pair<int ,int >> moves = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };
        for(int i=0 ; i< rows; i++){
            for(int j = 0 ; j< cols; j++){
                  if(mat[i][j] == 0 ){
                    q.push({i,j});
                }
                    else{
                        mat[i][j] = INT_MAX;
                    }
                }    
            }              
                    while(!q.empty()){
                        auto curr = q.front();
                        q.pop();
                        int r = curr.first;
                        int c = curr.second;
                        for(auto move : moves){
                
                            int nr = r + move.first;
                            int nc = c + move.second;
                            if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && mat[nr][nc] > mat[r][c]+ 1){
                                 mat[nr][nc] = mat[r][c] + 1;
                                 q.push({nr,nc});

                            }
                            
                        }
                    }

            
        
        return mat ;
    }
};
