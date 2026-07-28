class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int , list<int>> adj;
        for(int i =0; i< relations.size() ; i++){
            int prev = relations[i][0];
            int next = relations[i][1];

            adj[prev].push_back(next);
        }
        vector<int> indegree(n+1,0);
        for(auto i : adj){
            for(auto j : i.second){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=1; i<= n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> finish(n + 1);
        for(int i =1 ; i<= n; i++){
            finish[i] = time[i-1];
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto neighbour : adj[front]){
                finish[neighbour] =max(finish[neighbour], finish[front] + time[neighbour-1]);

                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }

            }
        }
        int ans = 0;
        for(int i =1 ; i<= n; i++)
            ans = max(ans, finish[i]);
        return ans;
    }
};


     
