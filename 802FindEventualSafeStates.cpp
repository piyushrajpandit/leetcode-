#appraoch 
in eventula safe state , a node is called is called safe node 
starting from that node, every possible path eventually ends at a teminal node 

terminal node means outdegree = 0 ;
we use dfs+ cycle detection 
we maintain 
vis-> node already visited globally 
pathVis -> node currently in dfs path 
safe -> node is safe or not 

what dfs does if it finds cycle it return true 
  else it return false 

step 1 mark visited 
vis[node] = 1; 
pathVis[node] = 1; 

step 2 visit neighbours 
for (auto nbr: graph[node] ) 
transvers all outgoing edges 

cycle detection 
if(pathVis[nbr]){
return true;
}
this is the key if neighbour already exiist in current dfs path cycle found means unsafe 

if (!vis[nbr]){
if(dfs(nbr, graph , vis, pathVis, safe){
reutrn true;
}
}
 if neighbour unvisited recursively check it 
if deeper call finds cycle propagete true 
   at the time of backtracking pathVis[node] = 0 ; 

mark safe safe[node] = 1
if exection reches here 
no cycel found for this node 
therefore safe 

return false 
no cycle 


class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> & vis, vector<int> & pathVis, vector<int> & safe){
        vis[node] = 1; 
        pathVis[node]= 1; 
        for(auto nbr: graph[node]){
            //cycle detected 
            if(pathVis[nbr]){
                return true;
            }
            if(!vis[nbr]){

                if(dfs(nbr, graph , vis, pathVis , safe)){
                    return true;
                }
            }
        }
        pathVis[node] = 0; 
        safe[node] = 1; 
        return false;
    }
   

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n,0);
        vector<int> safe(n,0);

        for(int i =0 ; i< n; i++){
            if(!vis[i]){
                dfs(i, graph , vis, pathVis, safe);
            }
        }
        vector<int> ans;
        for(int i =0 ; i< n ; i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
    return ans;
    }
};
