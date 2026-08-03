// 1. Build the weighted undirected graph using an adjacency list.
//
// 2. Run Dijkstra from node 'n' to compute the shortest distance
//    from every node to node 'n'.
//
// 3. Use a min-heap (distance, node) to always process the
//    closest unvisited node.
//
// 4. Ignore stale entries:
//    if (currDist > dist[currNode]) continue;
//
// 5. Relax every adjacent edge:
//    if (currDist + weight < dist[nextNode])
//    update dist[nextNode] and push it into the priority queue.
//
// 6. After Dijkstra, dist[] contains the shortest distance
//    from each node to node 'n'.
//
// 7. Apply DFS + Memoization.
//
// 8. dfs(node) returns the number of restricted paths
//    from 'node' to node 'n'.
//
// 9. Base case:
//    If node == n, return 1.
//
// 10. If the answer for this node is already computed,
//     return the memoized value.
//
// 11. Visit only neighbors satisfying:
//     dist[node] > dist[nextNode]
//     because a restricted path must strictly decrease
//     in shortest distance to node 'n'.
//
// 12. Sum the number of restricted paths from all valid neighbors.
//
// 13. Store the answer in dp[node] and return it.
//
// 14. Return dfs(1), which gives the number of restricted
//     paths from node 1 to node n.
//
// Time Complexity:
// O((V + E) log V) + O(V + E)
//
// Space Complexity:
// O(V + E)

class Solution {
public:
    const int MOD = 1e9 + 7;
    int dfs(int node,int n,vector<int>& dp,vector<vector<pair<int ,int>>>& adj,vector<int>&dist){
        //base case 
        int ans = 0;
        if(node == n) return 1;
        if(dp[node] != -1 ) return dp[node];
        for(auto neigh : adj[node]){
            int nextNode = neigh.first;
            if(dist[node] > dist[nextNode]){
               ans = (dfs(nextNode,n,dp,adj,dist) + ans ) % MOD;
        }}
         return dp[node] = ans % MOD;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int ,int>>> adj(n+1);
        for(int i=0; i< edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0, n});
        vector<int> dist(n+ 1,INT_MAX);
        dist[n] =0;
        
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int currdist = curr.first;
            int currnode = curr.second;
            if(currdist > dist[currnode]) continue;
            for(auto neigh : adj[currnode]){
                int nextNode = neigh.first;
                int weight = neigh.second;
                int newdist = weight + currdist;
                if(dist[nextNode] > newdist){
                    dist[nextNode] = weight + currdist;
                    pq.push({dist[nextNode],nextNode});
                }

            }

        }
        vector<int> dp(n, -1);
        return dfs(1,n,dp,adj,dist);

    }
}; 
