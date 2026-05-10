#apprach 
we have to remoce the node dissconte the graph 
track two things discovery time and lowest reachable ancestor 
an we store whether it is visited or not 
and ap[]

steps
1. mark visited 
2. disc[node] = low[node] = timer++;
3. int child = 0
  count dfs children 
4. transverse neighbour 
5. if nbr == parent ingonre it its parent 
6. if not vis[nbr] dfs deeper 
7. update low[node] = min(low[node] , low[nbr]);
means child subtreee reach earlier ancestor 


8. core concept 
if (low[nbr] > = disc[node] && parent != -1)
  if child subtree cannot reach ancestor of node 
then removeoing current node disconnects subtree 
so node became artuclation point 

8. increase child++ 
  back edge case 
  low[node] = min(low[node] , disc[nbr]);









#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

int mini(int a, int b) {

    if(a < b)
        return a;

    return b;
}

void dfs(int node,
         int parent,
         vector<int> &disc,
         vector<int> &low,
         unordered_map<int, bool> &vis,
         unordered_map<int, list<int>> &adj,
         vector<int> &ap,
         int &timer) {

    vis[node] = true;

    disc[node] = low[node] = timer++;

    int child = 0;

    for(auto nbr : adj[node]) {

        if(nbr == parent)
            continue;

        if(!vis[nbr]) {

            dfs(nbr,
                node,
                disc,
                low,
                vis,
                adj,
                ap,
                timer);

            low[node] =
                min(low[node], low[nbr]);

            // articulation point check
            if(low[nbr] >= disc[node] &&
               parent != -1) {

                ap[node] = true;
            }

            child++;
        }

        else {

            low[node] =
                min(low[node], disc[nbr]);
        }
    }

    // special case for root node
    if(parent == -1 && child > 1) {
        ap[node] = 1;
    }
}

int main() {

    int n = 5;
    int e = 5;

    vector<pair<int, int>> edges;

    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    // adjacency list
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < edges.size(); i++) {

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;

    vector<int> disc(n);
    vector<int> low(n);

    unordered_map<int, bool> vis;

    vector<int> ap(n, 0);

    for(int i = 0; i < n; i++) {

        disc[i] = -1;
        low[i] = -1;
    }

    // DFS
    for(int i = 0; i < n; i++) {

        if(!vis[i]) {

            dfs(i,
                -1,
                disc,
                low,
                vis,
                adj,
                ap,
                timer);
        }
    }

    // print articulation points
    cout << "Articulation points are:" << endl;

    for(int i = 0; i < n; i++) {

        if(ap[i] != 0) {

            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}
