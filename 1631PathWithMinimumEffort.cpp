
/*this is the question of distra here we have create one dist that contain row, column and distance
set is create which also contain three things
now we move step by step and when save two things edge diffrence 
   int edgeDifference = abs(heights[row][col] - heights[nr][nc]);
    int newEffort = max(effort, edgeDifference);


  if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        st.insert({dist[nr][nc],{nr,nc}});
                    }

*/

class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        set<pair<int ,pair<int, int>>> st;
        dist[0][0] = 0;
        st.insert({0,{0,0}});
        vector<pair<int,int>> moves = {
            {1,0}
            ,{-1,0}
            ,{0,-1},
            {0,1}
        };
       
        while(!st.empty()){
            auto top = *st.begin();
            st.erase(st.begin()); 
            int effort = top.first;
            int row = top.second.first;
            int col = top.second.second;
            
   
            for(auto move : moves){
                int nr = row + move.first;
                int nc = col + move.second;
                if(nr >= 0 && nc >= 0 && nr < rows && nc < cols ){
                    int edgeDifference = abs(heights[row][col] - heights[nr][nc]);
                    int newEffort = max(effort, edgeDifference);
                    
                
                    
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        st.insert({dist[nr][nc],{nr,nc}});
                    }
                        
            }
               
            }
        }
        return dist[rows-1][cols-1];
    }
};
