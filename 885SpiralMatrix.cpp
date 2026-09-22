/*
Approach: Spiral Matrix III

- Start from (rStart, cStart) and add the starting cell.
- Move in spiral order: Right -> Down -> Left -> Up.
- The number of steps increases after every TWO directions:
      Right = 1, Down = 1
      Left  = 2, Up   = 2
      Right = 3, Down = 3
      Left  = 4, Up   = 4 ...
- For every movement, update rStart/cStart first.
- A position may go outside the matrix. That is allowed.
- Only add the position to result if:
      0 <= rStart < rows
      0 <= cStart < cols
- Increase step once after Down and once after Up.
- Stop when result contains rows * cols cells.

Key point:
The spiral movement continues even outside the matrix.
The boundary check is ONLY for deciding whether to store the cell.
*/
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int step =1;
        result.push_back({rStart, cStart});
        while(result.size() != rows*cols){
            //left to right 
            for(int i =0 ; i< step ; i++){
                cStart++;
                if(rStart >=0 && rStart < rows &&
                cStart >=0 && cStart < cols){
                    result.push_back({rStart, cStart});
                }
            }
            
            //down chalo 
           for(int i =0 ; i< step ; i++){
                rStart++;
                if(rStart >=0 && rStart < rows &&
                cStart >=0 && cStart < cols){
                    result.push_back({rStart, cStart});
                }
            }

            step++;
            //right to left 
           for(int i =0 ; i< step ; i++){
                cStart--;
                if(rStart >=0 && rStart < rows &&
                cStart >=0 && cStart < cols){
                    result.push_back({rStart, cStart});
                }
            }


            //down to up 
            for(int i =0 ; i< step ; i++){
                rStart--;
                if(rStart >=0 && rStart < rows &&
                cStart >=0 && cStart < cols){
                    result.push_back({rStart, cStart});
                }
            }
            step++;
        }
        return result;
    }
};
