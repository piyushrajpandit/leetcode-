/*
Approach:

* Every diagonal contains elements whose row + column index is the same.
* Traverse diagonals using d = 0 to m + n - 2.
* If d is even, traverse the diagonal upward-right (row--, col++).
* If d is odd, traverse the diagonal downward-left (row++, col--).
* For each diagonal, calculate a valid starting position depending on whether
  the diagonal starts from the top row or the last column/row.
* Keep moving while the row and column stay inside the matrix.
* Add every visited element to the answer vector.

Example:
1 2 3
4 5 6
7 8 9

Traversal:
1 → 2 4 → 7 5 3 → 6 8 → 9

Result:
[1, 2, 4, 7, 5, 3, 6, 8, 9]

Time Complexity: O(m * n)
Space Complexity: O(1) extra space (excluding the answer vector)
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
      
        for(int d = 0; d< m + n -1; d++){
            if(d % 2 == 0){
                int row =  min ( d, m-1);
                int col = d -row;
                while(row>= 0 && col < n){
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
            }
            else{
                int col = min ( d, n -1);
                int row = d- col;
                while(col >= 0 && row < m){
                    ans.push_back(mat[row][col]);
                    row++;
                    col--;
                }

            }
        }
        return ans;
    }
};
