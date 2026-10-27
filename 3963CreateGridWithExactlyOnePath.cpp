class Solution {
public:

    vector<string> createGrid(int m, int n) {
       vector<string> grid(m, string(n, '#'));
        
        // Fill top row with '.'
        grid[0] = string(n, '.');
        
        // Fill rightmost column with '.'
        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};
