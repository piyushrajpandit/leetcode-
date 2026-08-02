
/*
Algorithm Summary (Modified Dijkstra)

1. Build an adjacency list for the undirected graph.

2. Maintain two arrival times for every node:
   - first[node]  = shortest time to reach the node.
   - second[node] = second shortest distinct time to reach the node.

3. Use a min-heap (priority queue) storing {currentTime, currentNode}.

4. Pop the earliest arrival time from the heap.
   - If this time is already greater than the second shortest time for that node,
     ignore it.

5. Before moving to neighbors, wait if the traffic signal is red.
   - If green, leave immediately.
   - If red, wait until it turns green.

6. Compute the arrival time for every neighbor.
   - If it improves the shortest time:
       -> Shift the previous shortest to second shortest.
       -> Update the shortest time.
       -> Push the new state into the heap.
   - Else if it improves only the second shortest time:
       -> Update the second shortest time.
       -> Push the new state into the heap.

7. After processing all states, return the second shortest time for node n.

Time Complexity: O((V + E) log V)
Space Complexity: O(V + E)
*/

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        priority_queue<pair<int, int >, vector<pair<int, int>> , greater<pair<int ,int>>> pq;
        const int INF = 1e9;
        vector<vector<int>> adj(n+1);
        vector<int> first(n + 1, INF);
        vector<int> second(n + 1, INF);
        for(int i =0 ;  i< edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
           
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        pq.push({0,1});
        first[1]= 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int currTime = curr.first;
            int currNode = curr.second;
            if(currTime > second[currNode]) continue;
            int depart = currTime;
            while(((depart / change )% 2) !=0) {
                     depart++;
            }

            for(auto neigh : adj[currNode]){
               
               int oldTime = first[neigh];
                
                  int newTime =  depart + time;
                  if(newTime < first[neigh]){
                    second[neigh] = first[neigh];
                    first[neigh] = newTime;
                    pq.push({first[neigh], neigh});
                  }
                  
                    else if(newTime > first[neigh] && newTime < second[neigh] ){
                            second[neigh] = newTime;
                        
                            pq.push({second[neigh], neigh});
                  }
                 
                  
            }
        }
        return second[n];
    }
};201
