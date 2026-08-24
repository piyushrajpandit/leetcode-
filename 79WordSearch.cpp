



/*
LeetCode 79 - Word Search

APPROACH:
- Use DFS + Backtracking.
- Start DFS from every cell that matches word[0].
- At each cell:
    1. Check if the entire word has been matched.
    2. Check if the cell is inside the board.
    3. Check if the current cell matches word[index].
    4. Mark the current cell as visited.
    5. Explore all 4 directions:
         - right
         - down
         - up
         - left
    6. If any direction finds the remaining word, return true.
    7. If all directions fail, restore the current cell.
       This is called BACKTRACKING.

WHY BACKTRACKING?
- A cell cannot be used more than once in the same path.
- We temporarily mark a cell as '#' to indicate it is being used.
- When a path fails, we restore the original character so that
  another possible path can use that cell.

DFS STATE:
    row, col  -> current position
    index     -> current character of word we are searching for

BASE CASE:
    if index == word.size()
        → entire word has been found
        → return true

INVALID CASES:
    - row/col is outside the board
    - board[row][col] != word[index]

IMPORTANT:
- Do NOT use a global index because different DFS paths can have
  different progress.
- Do NOT use BFS/queue because we need to explore complete paths
  and backtrack when a path fails.

TIME COMPLEXITY:
    O(rows * cols * 4^L)

    where L = length of word.

SPACE COMPLEXITY:
    O(L) for the recursion stack.
*/

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word, int row , int col , int index){
        if(index == word.size()){
            return true;
        }
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()){
            return false;
        }
        if(board[row][col] != word[index]){
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '#';
        vector<pair<int,int>> directions = {
                {0, 1},
                {1, 0},
                {-1, 0},
                {0, -1}
        };
        for (auto [dr, dc] : directions) {
                int nextRow = row + dr;
                int nextCol = col + dc;

                if(dfs(board, word, nextRow, nextCol , index+1))
                    return true;
                
        }
      board[row][col] = temp;
      return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
      
        int rows = board.size();
        int cols = board[0].size();
        for(int row = 0 ; row< rows; row++){
            for(int col = 0; col < cols; col++){
                if(board[row][col] == word[0]){
                    if(dfs(board,word,row, col, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
