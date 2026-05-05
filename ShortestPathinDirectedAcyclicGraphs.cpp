
// approch this is the somple code you have to do simple things 
// first while adding in garph you have three thing first is from where and second is form where to 
// where and what is its weight 

// now 

// lets go to dfs part 
// here we make dfs visited 
// now we go for the neighbour node 
// if neighbour node not visisted call dfs for it 
// at last we push the node in topo


// now the last part getsortestpath 
// here make dis[src] = 0 
// while (!topo not empty we have do take top element and pop it 
// noe we put that element and check if its noe equal to int_max
//  now start with neighbours 
// we add dis from top and wt and if its less than dist[v] we will make dist[v] equla to dis[top] + wt 


#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
    }

    // DFS for Topological Sort
    void dfs(int node,
             unordered_map<int, bool>& vis,
             stack<int>& topo) {

        vis[node] = true;

        for (auto neighbour : adj[node]) {
            int nextNode = neighbour.first;

            if (!vis[nextNode]) {
                dfs(nextNode, vis, topo);
            }
        }

        topo.push(node);
    }

    // Shortest Path in DAG
    void getShortestPath(int src,
                         vector<int>& dist,
                         stack<int>& topo) {

        dist[src] = 0;

        while (!topo.empty()) {
            int top = topo.top();
            topo.pop();

            // check if node already reachable
            if (dist[top] != INT_MAX) {

                for (auto neighbour : adj[top]) {

                    int v = neighbour.first;
                    int wt = neighbour.second;

                    if (dist[top] + wt < dist[v]) {
                        dist[v] = dist[top] + wt;
                    }
                }
            }
        }
    }
};

int main() {

    Graph g;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int n = 6;

    // Topological Sort
    unordered_map<int, bool> vis;
    stack<int> topo;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            g.dfs(i, vis, topo);
        }
    }

    // Distance array
    vector<int> dist(n, INT_MAX);

    int src = 1;

    // Find shortest paths
    g.getShortestPath(src, dist, topo);

    // Print answer
    cout << "Shortest distances from source " << src << ":\n";

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}
