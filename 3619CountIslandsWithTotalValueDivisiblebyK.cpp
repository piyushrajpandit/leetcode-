class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if(grid.empty())
            return 0 ;
        int row = grid.size();
        int count = 0;
        int col = grid[0].size();
        vector<vector<int>> visited(row,vector<int>(col, 0));
        int island = 0;
        queue<pair<int, int>> que;
        vector<pair<int,int>> moves = {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1}
        };
        for(int i =0 ; i< row ; i++){
            for(int j = 0 ; j< col ; j++){
                if(grid[i][j] != 0 && visited[i][j] == 0 ){
                    que.push({i,j});
                    visited[i][j] = 1;
                    long long sum = 0;
                
                while(!que.empty()){
                    auto temp = que.front();
                    que.pop();

                    int r= temp.first;
                    int c = temp.second;
                     sum += grid[r][c];
                  
                    for(auto next : moves){
                        int rt = next.first + r;
                        int ct= next.second + c;

                        if(rt >= 0 && rt < row &&
                            ct >= 0 && ct < col &&
                            grid[rt][ct] != 0 &&
                            visited[rt][ct] == 0){
                                visited[rt][ct]=1;
                            que.push({rt,ct});
                            }
                        }
                    }
                    if(sum % k == 0) 
                        count++;

                }
            }
        }
        return count;
    }
};
