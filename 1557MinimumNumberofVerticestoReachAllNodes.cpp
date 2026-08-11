// LeetCode 1557 - Minimum Number of Vertices to Reach All Nodes
//
// Approach: Indegree
//
// 1. Create an indegree array of size n.
//    indegree[i] stores how many edges are coming into node i.
//
// 2. For every directed edge u -> v:
//       increase indegree[v].
//
// 3. A node with indegree 0 has no incoming edge,
//    so no other node can reach it.
//    Therefore, it MUST be included in the answer.
//
// 4. Traverse all nodes:
//       if indegree[i] == 0,
//       add node i to the answer.
//
// 5. No adjacency list, DFS, BFS, or DSU is needed.
//
// Time Complexity: O(n + edges.size())
// Space Complexity: O(n)
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        vector<int> ans;
        vector<vector<int>> adj(n);
        for(int i =0; i< edges.size(); i++){
            int u =edges[i][0];
            int v = edges[i][1];
            indegree[v]++;
        }
       
        for(int i=0; i< indegree.size(); i++){
            if(indegree[i] == 0 )
            ans.push_back(i);
        }
        return ans;
    }
};
