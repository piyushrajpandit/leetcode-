// what we have to do 
//   we have to make adjacency list and then 
// make a dist vector  mark source = 0
// now insert that pair nin stack 
// and take top element to stack and pop if and go to its neigbour
// by neighbour if got distance less than intial than replace it with new one and delete the last one 
// and insert that in stack and 
// now return the lowest one 


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    
    for (int i = 0; i < times.size(); i++) {

        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];

        adj[u].push_back(make_pair(v, w));
       
    }

    // Distance array initialize with INF
    vector<int> dist(n+1, INT_MAX);

    // Set -> (distance, node)
    set<pair<int, int>> st;

    // Source node
    dist[k] = 0;
    st.insert(make_pair(0, k));

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
    int maxi  = INT_MIN;
    for(int i = 1 ; i<= n;i++){
        // unreachable node
        if(dist[i] == INT_MAX) {
        return -1;
    }
        
            maxi =max( dist[i], maxi);
        
    }
        return maxi;

    }
};



