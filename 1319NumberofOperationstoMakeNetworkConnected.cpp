// this kind of code i have written few days ago so its easy for me 
// Summary:
//
// 1. 'parent' array stores the representative (parent) of each node.
//
// 2. find(i):
//    - Finds the ultimate parent (root) of node i.
//    - Uses path compression to make future searches faster.
//
// 3. unite(i, j):
//    - Finds the roots of both nodes.
//    - If both have the same root, they are already connected,
//      so this edge is redundant (cycle).
//    - Otherwise, merges the two sets by making one root the
//      parent of the other.
//
// 4. makeConnected():
//    - If total cables < (n - 1), connecting all computers
//      is impossible, so return -1.
//    - Initialize every node as its own parent.
//    - Process each connection using DSU.
//    - Count redundant (extra) edges when unite() returns false.
//    - Count the number of connected components.
//    - Required cables = components - 1.
//    - If extra cables are enough, return required cables;
//      otherwise return -1.




class Solution {
public:
    vector<int> parent;
    int find(int i){
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j ){
        int rootI = find(i);
        int rootJ = find(j);
        if(rootI == rootJ){
            return false; // cycle detected
        }
        parent[rootI] = rootJ;//metge sets
        return true;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        int k = connections.size();
        parent.resize(n+1);

        for(int i =0; i< n; i++)
            parent[i] = i;
        int extra = 0 ;
        for(const auto& edge : connections){
            int u = edge[0];
            int v = edge[1];
            if(!unite(u,v)){
                extra++;
            }
        }

        int components = 0;

        for(int i = 0; i < n; i++) {
            if(find(i) == i)
                components++;
            }

        int needed = components - 1;
        if(extra >= needed)
            return needed;
        
        return -1;
        
    }
};
