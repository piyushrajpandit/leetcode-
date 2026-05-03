class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
            //create adjacency list 
            unordered_map<int , list<int>> adj;
            for(int i =0 ; i< prerequisites.size(); i++){
                int u = prerequisites[i][1];
                int v = prerequisites[i][0];
                adj[u].push_back(v);
                

            }
            //indegree vector
            vector<int> indegree(numCourses, 0);
        
            //calculate indegree
            for(auto i: adj){
                for(auto j: i.second){
                    indegree[j]++;

                }
            }
            //queue for 0 indegree nodes 
            queue<int> q; 
            for(int i =0 ; i< numCourses;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        //bfs 
        int count = 0;
         while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;

         
        for(auto neighbour :adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);

            }
        }
        }
        // if all nodes processes ->no cycle
        return count == numCourses;


            
        }
    

};
