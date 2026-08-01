/*
Approach: Dijkstra's Algorithm (Minimum Maximum Cost)

- Treat each cell as a node in a graph.
- Moving to a neighboring cell takes time equal to the maximum elevation
  encountered on the path so far.
- Maintain a distance matrix where dist[r][c] stores the minimum time
  required to reach cell (r, c).
- Use a set (min-priority queue) to always process the cell with the
  smallest current time.
- For each valid neighbor:
      newTime = max(currentTime, grid[nr][nc])
  If newTime is smaller than the recorded value, update dist and
  insert the neighbor into the set.
- The answer is dist[n-1][n-1], which represents the earliest time
  at which the bottom-right cell can be reached.

Time Complexity: O(n² log(n²)) = O(n² log n)
Space Complexity: O(n²)
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dist(rows,vector<int> (cols , INT_MAX));
        set<pair<int, pair<int, int>>> st;
        dist[0][0] = grid[0][0];
        st.insert({grid[0][0],{0,0}});
        vector<pair<int,int>> moves = {
            {1,0},
            {-1,0},
            {0,-1},
            {0,1}
        };
        while(!st.empty()){
            auto top =*st.begin();
            st.erase(st.begin());
            int currTime = top.first;
            int row = top.second.first;
            int col =top.second.second;

            for(auto move: moves){
                int nr = row + move.first;
                int nc = col + move.second;
                if(nr >= 0 && nc >= 0 && nr < rows && nc < cols){
                    
                    int newTime = max(currTime , grid[nr][nc]);
                    if(newTime < dist[nr][nc]){
                        dist[nr][nc] = newTime;
                        st.insert({newTime, {nr,nc}});
                    }
                }
            }
        }
        return dist[rows-1][cols-1];
    }
};
