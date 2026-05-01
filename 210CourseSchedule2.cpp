class Solution {
public:

    bool toposort(int node,
                  unordered_map<int, bool>& visited,
                  unordered_map<int, bool>& dfsVisited,
                  stack<int>& s,
                  unordered_map<int, list<int>>& adj) {

        visited[node] = true;
        dfsVisited[node] = true;

        for(auto neighbour : adj[node]) {

            if(!visited[neighbour]) {

                bool cycleDetected =
                    toposort(neighbour,
                             visited,
                             dfsVisited,
                             s,
                             adj);

                if(cycleDetected)
                    return true;
            }

            else if(dfsVisited[neighbour]) {
                return true;
            }
        }

        dfsVisited[node] = false;

        s.push(node);

        return false;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        unordered_map<int, list<int>> adj;

        for(int i = 0; i < prerequisites.size(); i++) {

            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;

        stack<int> s;

        for(int i = 0; i < numCourses; i++) {

            if(!visited[i]) {

                bool cycleDetected =
                    toposort(i,
                             visited,
                             dfsVisited,
                             s,
                             adj);

                if(cycleDetected)
                    return {};
            }
        }

        vector<int> ans;

        while(!s.empty()) {

            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};
