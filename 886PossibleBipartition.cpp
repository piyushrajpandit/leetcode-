// Summary:
//
// 1. Build an undirected graph using the dislikes array.
//    Each person is a node, and each dislike relationship is an edge.
//
// 2. Use a color array:
//      -1 = Not visited
//       0 = Group A
//       1 = Group B
//
// 3. Traverse every node because the graph may have multiple
//    disconnected components.
//
// 4. For every unvisited node, start BFS:
//      - Assign the starting node a color.
//      - Color every neighbor with the opposite color.
//      - Continue until the entire connected component is processed.
//
// 5. If a neighbor is already colored with the same color as the
//    current node, a valid bipartition is impossible, so return false.
//
// 6. If BFS finishes for all components without any conflict,
//    return true.

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1); 
        for(int i =0 ; i< dislikes.size(); i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<int> color(n+ 1, -1 );
        queue<int> q;
        for(int i =0 ; i<= n; i++){
            if(color[i] == -1){
                color[i] = 1; 
                q.push(i);
                while(!q.empty()){
                    int temp = q.front();
                    q.pop();
                    for(auto next : adj[temp]){
                        if(color[next] == -1){
                            color[next] = 1- color[temp];
                            q.push(next);
                        }
                        else if(color[next] == color[temp]){
                            return false;
                        }
                    }
                }
            }
        }
    return true;
    }
};
