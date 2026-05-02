# Topological Sort using Kahn's Algorithm

## Algorithm
1. Create adjacency list
2. Find indegree of all nodes
3. Push all nodes with indegree 0 into queue
4. Perform BFS
5. Reduce indegree of neighbours
6. If neighbour indegree becomes 0, push into queue

## Time Complexity
O(V + E)

## Space Complexity
O(V + E)

## Code

```cpp
class Solution {
public:

    vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {

        unordered_map<int, list<int>> adj;

        for(int i = 0; i < e; i++) {

            int u = edges[i][0];
            int node = edges[i][1];

            adj[u].push_back(node);
        }

        vector<int> indegree(v, 0);

        for(auto i : adj) {
            for(auto j : i.second) {
                indegree[j]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < v; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {

            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto neighbour : adj[front]) {

                indegree[neighbour]--;

                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};
