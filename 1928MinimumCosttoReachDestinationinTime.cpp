class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
      
      vector<vector<int>> cost(passingFees.size(),vector<int>(maxTime+1,INT_MAX));
      priority_queue<tuple<int, int, int>,vector<tuple<int,int, int>>,greater<tuple<int ,int , int>>>  pq;


      vector<vector<pair<int,int>>> adj(passingFees.size());
      for(int i =0;  i< edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int time = edges[i][2];
        adj[u].push_back({v,time});
        adj[v].push_back({u,time});

      }
      

      pq.push({passingFees[0], 0, 0});
      cost[0][0] = passingFees[0];
     
      while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int currCost = get<0>(curr);
        int node = get<1>(curr);
        int time = get<2>(curr);
        if(cost[node][time] < currCost) continue;
        for(auto neigh : adj[node]){
          
            int nextnode = neigh.first;
            int nexttime = neigh.second;

            int nextnodecost = passingFees[nextnode] + currCost;
            int nextnodetime = time + nexttime;

            if(nextnodetime <= maxTime &&nextnodecost < cost[nextnode][nextnodetime]  ){
                cost[nextnode][nextnodetime] = nextnodecost;
              
                pq.push({nextnodecost, nextnode, nextnodetime});
            }
        }
      }
    int destination = passingFees.size() -1 ;
    int ans = INT_MAX;
    for(int t =0; t<= maxTime ; t++){
        ans = min(ans, cost[destination][t]);
    }
    return ans == INT_MAX ? -1: ans;
    }
};
