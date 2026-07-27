//simple code we have to bfs 
we have just move
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];

        if (original == color)
            return image;
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        
        vector<pair<int,int>> moves = {
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };
        
        
        while(!q.empty()){
            auto curr = q.front();
            
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for(auto move : moves){
                
                int nr = r + move.first;
                int nc = c + move.second;
                
               
                    if (nr >= 0 && nr < image.size() &&
                        nc >= 0 && nc < image[0].size() &&
                        image[nr][nc] == original){
                        image[nr][nc] = color;
                        q.push({nr, nc});
             
                    }
                
            }
        }
        return image;
    }
};

