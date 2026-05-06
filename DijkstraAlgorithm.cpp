approch 
first thing is it find the sortest distance from one source node to all other node in a grapk
1. make adjacency list 
  to mkae this you have to make unordered_map for int int int last tow int in pair 
  means u -> v and wieight 
2.  now start a distacne array make name all the vertices and make it int_max
 make for source = 0 
3. insert source in set 
4. process smallest distance node 
   do it till st is not empty 
    take top element means smallest and erase it 
    and traverse to its neighbour 
5. next step is relaxtion 
  if nodedistance + neighbout distance < distance of neigbour  means we find the sortest distance 
  so make dist[i] = 4 ;
  and st.insert that pair 
 and erase outdates record auto record = st.find(make_pair(dist[neighbourNode],
                                neighbourNode)); 
 and delete the record 





#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec,
                     int vertices,
                     int edges,
                     int source) {

    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++) {

        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Distance array initialize with INF
    vector<int> dist(vertices, INT_MAX);

    // Set -> (distance, node)
    set<pair<int, int>> st;

    // Source node
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty()) {

        // Fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // Remove top record
        st.erase(st.begin());

        // Traverse neighbours
        for (auto neighbour : adj[topNode]) {

            int neighbourNode = neighbour.first;
            int neighbourDistance = neighbour.second;

            // Relaxation
            if (nodeDistance + neighbourDistance < dist[neighbourNode]) {

                // Check if record already exists
                auto record =
                    st.find(make_pair(dist[neighbourNode],
                                      neighbourNode));

                // If found, erase old record
                if (record != st.end()) {
                    st.erase(record);
                }

                // Update distance
                dist[neighbourNode] =
                    nodeDistance + neighbourDistance;

                // Insert updated record
                st.insert(make_pair(dist[neighbourNode],
                                    neighbourNode));
            }
        }
    }

    return dist;
}
