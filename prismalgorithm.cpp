core idea
main thing is to find the minimum total edge cost 
1. key  minimum edges wight needed to connect node 
2. mst whether already inlcuded in mst 
3. parent  for which node current node is connected 
step 1 start fro mnode 1  make key  = 1
step 2  find node with minimum key value not yet included
step 3 include in mst  mst[u] = true 
step 4 update adj nodes means found cheaper edge connected to node v so update parent and key 



#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>>
calculatePrimsMST(int n,
                  int m,
                  vector<pair<pair<int, int>, int>> &g) {

    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++) {

        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Arrays
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Start from node 1
    key[1] = 0;
    parent[1] = -1;

    // Prim's Algorithm
    for (int i = 1; i < n; i++) {

        int mini = INT_MAX;
        int u;

        // Find minimum key node
        for (int v = 1; v <= n; v++) {

            if (mst[v] == false &&
                key[v] < mini) {

                u = v;
                mini = key[v];
            }
        }

        // Mark min node as visited
        mst[u] = true;

        // Traverse adjacent nodes
        for (auto it : adj[u]) {

            int v = it.first;
            int w = it.second;

            if (mst[v] == false &&
                w < key[v]) {

                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // Prepare result
    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++) {

        result.push_back(
            make_pair(
                make_pair(parent[i], i),
                key[i]
            )
        );
    }

    return result;
}
