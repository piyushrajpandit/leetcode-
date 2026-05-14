// here we have to bfs of grid nut for that make a pair beacuse it can move only in 4 diresction 
//   int row and column  start a loop and push the pair <i,j> if its 2 then push in q and 
// them if its 1 we have to increse fresh count by one 
// if fresh count = 0 return 0 
//   int minitute =0 we also have to count miniute 
// now direction vector we have to make  {1,0},{-1,0},{0,1},{0,-1}
// now start a while loop till q is not empty 
// int size = q.size and bool rottenthis minute = false 
//   start a for loop and take the first elment and pop if 
//   a nd make x and y increse it all the four direction 

//      valid fresh orange 
//                     if(nx >=0 && ny >=0 && nx < row && ny < cols && grid[nx][ny] ==1 ){
// then make it rottten and push in q and decrese fresh 
// amd make rottenthis minute = true 

//   if some ting is rotten this miniute and then increse minute 
// and if not fresh != 0 

//   return minutes 



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int row = grid.size();
        int cols = grid[0].size();

        queue<pair<int , int>> q;
        int fresh = 0;
       
        for(int i =0 ; i<row; i++){
            
            for(int j  =0 ; j< cols ;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] ==1 ){
                    fresh++;
                }
            }
        }
        //no fresh oranges 
        if(fresh == 0)
            return 0;
        int minutes =0;

        vector<pair<int, int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        while(!q.empty()){
            int size = q.size();
            bool rottenThisMinute = false;
            for(int i=0 ; i< size; i++){
                auto front = q.front();
                q.pop();

                int x = front.first;
                int y = front.second;

                for(auto d: dir){
                    int nx = x + d.first;
                    int ny = y + d.second;

                    //valid fresh orange 
                    if(nx >=0 && ny >=0 && nx < row && ny < cols && grid[nx][ny] ==1 ){
                        grid[nx][ny] =2;
                        q.push({nx, ny});
                        fresh--;
                        rottenThisMinute = true;

                    }
                }
            }
            if(rottenThisMinute)
                minutes++;

                }
            
    if(fresh != 0)
        return -1;

    return minutes;



        
    }
};
