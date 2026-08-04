/**
 * Graph Valid Path Finder using Disjoint Set Union (DSU)
 * 
 * Approach Summary:
 * 1. Represents the graph components using a Parent Array.
 * 2. Initializes each node as its own parent/independent set.
 * 3. Iterates through all given edges to merge connected components.
 * 4. Utilizes Path Compression in 'find' for O(alpha(N)) efficiency.
 * 5. Checks if source and destination share the same ultimate root.
 * 
 * Space Complexity: O(N) to store the parent array.
 * Time Complexity:  O(N + E * alpha(N)), near-linear time execution.
 */


class Solution {
public:
    vector<int> parent;
    int find(int i){
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j){
        int rootI = find(i);
        int rootJ = find(j);
        if(rootI == rootJ){
            return false; //cycle detected
        }
        parent[rootI] = rootJ;//Merge sets
        return true;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        for(int i =0 ; i<edges.size() ;i++){
            parent[i] = i;
        }
        
        for(int i=0; i<=n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
           
            unite(u,v);
                
        }
        return find(source) == find(destination);
          
    }
};
