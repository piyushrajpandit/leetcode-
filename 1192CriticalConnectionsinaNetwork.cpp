// #approach 
// what is bridge 
// find all the edges which , if removed , disconnected the graph 


// idea is for you have to store every node 
// two things  disc[i] discovery time and 
// low[i] lowest discovery reachable 

// now if your low[nbr] > dis[node] 
// then edge
// node -> nbr is a bridge 
// because child subtree cannot go back upward 
// removing edge disconnected child subtree

// step by step variable 
// 1 adjacent list making 
// 2 discovery array disc[0] = 0 and disc[1] = 1 stoe dfs visiting order 
// 3 low node meand smallest discovery time reachable for this node including back edges and dwscendants 
// 4 timer every dfs visit increments timers 


// now lets see the dfs flow 
// enter node 
// disc[node] = low[node] = timer++;
// node = 3
// disc[3] = 3
// low[3] = 3

// traverse neighbour 
// ignore if parent if(nbr= parent ) continue ;
// if unvisited neighbour call recursive neighbour (nbr, node, ...) 

// after dfs return return lowest value 
// low[node] = mon(low[node], low[nbr]);
// meaning can my child reach someone above me?




// how to find back edge 
// if something is visited and not parent 





class Solution {
public:
void dfs(int node , int parent , int& timer , vector<int> &disc, vector<int> &low, vector<vector<int>> &result
, unordered_map<int, list<int>>& adj, unordered_map<int ,bool> & vis){
  vis[node] = true;
  disc[node] = low[node] = timer++;
  for(auto nbr:adj[node]){
    if(nbr == parent)
      continue;
    if(!vis[nbr]){
      dfs(nbr, node, timer, disc, low , result, adj, vis);
      low[node] =min(low[node], low[nbr]);
      //check edges is bridge
      if(low[nbr] > disc[node]){
        vector<int> ans;
        ans.push_back(node);
        ans.push_back(nbr);
        result.push_back(ans);
    }
    }
    else{
      //node already visited and not parent 
      //back edge
      low[node] = min(low[node],disc[nbr]); 
    }

    
}
}




    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    //adj list 
    unordered_map<int, list<int> > adj;
    for(int i =0 ; i< connections.size();i++){
    int u = connections[i][0];
    int v = connections[i][1];

    adj[u].push_back(v);
    adj[v].push_back(u);

    }
    int timer = 0 ;
    vector<int> disc(n);
    vector<int> low(n);
    int parent = -1; 
    unordered_map<int, bool> vis;

    for(int i =0 ; i< n; i++){
    disc[i] = -1;
    low[i] = -1 ;
    }
    vector<vector<int>> result;
    //dfs
    for(int i =0 ; i< n ;i++){
    if(!vis[i]){
    dfs(i, parent, timer, disc, low ,result, adj,vis);
    }
    }
    return result;

    }
};
