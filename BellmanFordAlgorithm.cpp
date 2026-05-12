here we have to do simple things first make dist and and you make to find dist[u] < wt + dist[v] n-1 times and the none time more if in lat time i
it gets updated then there is negative cylce 


#include <bits/stdc++.h>
using namespace std;

int bellmanFord(int n, int src, int dest, vector<vector<int>> &edges) {

    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    int m = edges.size();

    // Relax all edges n-1 times
    for (int i = 1; i <= n - 1; i++) {

        for (int j = 0; j < m; j++) {

            int u  = edges[j][0];
            int v  = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check negative cycle
    for (int j = 0; j < m; j++) {

        int u  = edges[j][0];
        int v  = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            return -1; // Negative cycle exists
        }
    }

    return dist[dest];
}
