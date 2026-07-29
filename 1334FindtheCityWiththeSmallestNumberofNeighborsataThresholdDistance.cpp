// for doing this question you should read 743 that is disktra algorithm 
// that is used to find the shortest distance from source node to all the node 
// we have to do that disktra for making all the nodes as source node and at last we 
// crate a variable count and if dist[i] < threshold then increse the count and put that into
// vector 
//  and in vector fond the minimum answer

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> answer;
        //create adj list 
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i=0; i< edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u, w});
        }

        for(int k =0 ; k< n; k++){
        set<pair<int, int>> st;
        vector<int> dist(n, INT_MAX);
             
        
        dist[k] = 0;
        st.insert(make_pair(0,k));

        while(!st.empty()){
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;

            //remove top record 
            st.erase(st.begin());

            for(auto neighbour : adj[topNode]){
                int neighbourNode = neighbour.first;
                int neighbourDistance = neighbour.second;

                if(nodeDistance + neighbourDistance < dist[neighbourNode]){
                    auto record  = st.find(make_pair(dist[neighbourNode], neighbourNode));

                    if(record != st.end()){
                        st.erase(record);

                    }
                    
                    dist[neighbourNode] = nodeDistance + neighbourDistance;

                    st.insert(make_pair(dist[neighbourNode], neighbourNode));
                    

                }
            }
        }
        int cnt = 0;
        for(int i= 0; i< n ;i++){
            
           if(i != k && dist[i] <= distanceThreshold)
                cnt++;
        }
            answer.push_back(cnt);

        }
        int ans = -1; 
        int mini = INT_MAX;
        for(int i =0; i< n; i++){
            if(answer[i] <= mini){
                mini = answer[i];
                ans = i;
            }
        }
        return ans;
    }
};
