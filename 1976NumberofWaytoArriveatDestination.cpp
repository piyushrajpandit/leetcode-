
// 1. Build the weighted undirected graph using an adjacency list.
//
// 2. Initialize:
//    - dist[i] = shortest distance from source (0) to node i.
//    - ways[i] = number of shortest paths to node i.
//
// 3. Set:
//    - dist[0] = 0
//    - ways[0] = 1
//
// 4. Use a min-heap (distance, node) to always process
//    the node with the smallest current distance.
//
// 5. Ignore stale entries:
//    if (currDist > dist[currNode]) continue;
//
// 6. For every neighbor of the current node:
//    - Calculate newDist = currDist + edgeWeight.
//
// 7. If a shorter path is found:
//    - Update dist[nextNode].
//    - Copy ways from the current node.
//    - Push the updated node into the priority queue.
//
// 8. If another shortest path with the same distance is found:
//    - Add the number of ways from the current node.
//    - Take modulo (1e9 + 7) to prevent overflow.
//
// 9. Continue until the priority queue becomes empty.
//
// 10. Return ways[n - 1], which is the total number
//     of shortest paths from node 0 to node n - 1.
//
// Time Complexity:
// O((V + E) log V)
//
// Space Complexity:
// O(V + E)
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        const long long INF = 1e18;
        vector<long long > dist(n,INF);
        vector<int> ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        vector<vector<pair<int,int>>> adj(n); 
        for(int i =0; i< roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});

        } 
        priority_queue<pair<long long,int>,vector<pair<long long ,int>>,greater<pair<long long, int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            long long  currdist = curr.first;
            int currnode = curr.second;
            if(currdist > dist[currnode]) continue;
            for(auto neigh: adj[currnode]){
                int nextnode = neigh.first;
                int weight = neigh.second;

                long long  newdist = currdist + weight;
                if(newdist == dist[nextnode]){
                    ways[nextnode] = (ways[nextnode] +ways[currnode])%MOD;
                }
                else if(newdist < dist[nextnode]){
                    dist[nextnode]  = newdist;
                    ways[nextnode] = ways[currnode];
                    pq.push({newdist, nextnode});
                }
            }
        }
        return ways[n-1];
    }
};
