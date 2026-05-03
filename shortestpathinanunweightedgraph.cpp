class Solution {
public:
    vector<int> sortestPath(vector<pair<int , int>> edges, int n, int m, int s, int t) {
        
            //create adjacency list 
            unordered_map<int , list<int>> adj;
            for(int i =0 ; i< edges; i++){
                int u = edges[i].first;
                int v = edges[i].second;
                adj[u].push_back(u);
                adj[v].push_back(v);

            }
            //do bfs 
            unordered_map<int , bool > visited;
            unordered_map<int , int > parent;
            queue<int> q;
            q.push(s);
            parent[s] = -1 ;

            visited[s] = true;

            while(!q.empty()){
                int front = q.front();
                q.pop();
                for(autp i: adj[front]){
                    if(!visited[i]){
                        visited[i] = true;
                        parent[i] = front;
                        q.push(i);
                    }
                }

            }
            //prepare shortest path
            vector<int>ans;
            int currentNode = t; 
            ans.push_back(t);
            while(currentNode !=s){
                currentNode = parent[currentNode];
                ans.push_back(currNode);
            }
            return ans;
        }
    

};
