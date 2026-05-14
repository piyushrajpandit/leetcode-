// in this question i used the concept of beelmansford and same code 
// just new thing is k at most stop 
// and we used temp also because in loop we if we not use it we change dist in every loop so we use temp 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n+1, 1e9);
        dist[src] = 0;
        int m = flights.size();

        //relax all edges n-1 times 
        for(int i =0 ; i<= k ; i++){
            vector<int> temp = dist;
            for(int j =0 ; j< m;j++){
            int u = flights[j][0];
            int v = flights[j][1];
            int wt = flights[j][2];
            if(dist[u]!= 1e9 && dist[u]+ wt< temp[v]){
                temp[v] = dist[u]+ wt;
            }

            }
            dist = temp;
        }if(dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};
