// topological sort 
// transpose 
// dfs and count 



#include <bits/stdc++.h>
using namespace std;

void dfs(int node,
         unordered_map<int, bool> &vis,
         stack<int> &st,
         unordered_map<int, list<int>> &adj) {

    vis[node] = true;

    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr, vis, st, adj);
        }
    }

    // store according to finishing time
    st.push(node);
}

void revDfs(int node,
            unordered_map<int, bool> &vis,
            unordered_map<int, list<int>> &transpose) {

    vis[node] = true;

    for (auto nbr : transpose[node]) {
        if (!vis[nbr]) {
            revDfs(nbr, vis, transpose);
        }
    }
}

int stronglyConnectedComponents(int V, vector<vector<int>> &edges) {

    // Step 1: Create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Step 2: Topological ordering using DFS
    stack<int> st;
    unordered_map<int, bool> vis;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    // Step 3: Create transpose graph
    unordered_map<int, list<int>> transpose;

    for (int i = 0; i < V; i++) {

        vis[i] = false;

        for (auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    // Step 4: DFS using stack order
    int count = 0;

    while (!st.empty()) {

        int top = st.top();
        st.pop();

        if (!vis[top]) {

            count++;

            revDfs(top, vis, transpose);
        }
    }

    return count;
}
