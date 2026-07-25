// Approach: Disjoint Set Union (Union-Find)
//
// 1. Create a parent array where each node is initially its own parent.
// 2. find(node):
//    - Finds the ultimate parent (leader) of the node.
//    - Uses Path Compression to make future searches faster.
// 3. unite(u, v):
//    - Find the leaders of both nodes.
//    - If both leaders are the same, adding this edge creates a cycle,
//      so return false.
//    - Otherwise, merge the two sets by connecting one leader to the other.
// 4. Process each edge:
//    - If unite(u, v) returns false, this edge is the redundant connection.
//    - Return that edge immediately.
// 5. If no redundant edge is found (not expected in this problem),
//    return an empty vector.
//
// Time Complexity: O(n * α(n)) ≈ O(n)
// Space Complexity: O(n)

// parent.resize(n + 1); 
// this is used to assign the newe size to the array 
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
            return false ; //cycle detected 

        }
        parent[rootI] = rootJ ; //Merge sets 
        return true ;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
   
        int n = edges.size();

        parent.resize(n + 1);

        for(int i = 0; i <= n; i++)
            parent[i] = i;
        
        for(const auto& edge : edges){
            int u = edge[0];
            int v= edge[1];
            if(!unite(u,v)){
                return {u,v};
            }
        }
        return {};
        
    }
};
