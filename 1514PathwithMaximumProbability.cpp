/*this far this is the best code which have done using ai the steps which i take invested my time soo much that a glance 
is enough to reivse it */

class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
       
        vector<vector<pair<int, double>>> adj(n);
        for(int i =0; i< edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});

        }
        

        priority_queue<pair<double, int> > st;
        vector<double> prob(n, 0);
        prob[start_node] = 1;
        st.push({1.0, start_node});

        while(!st.empty()){
            auto curr = st.top();
            st.pop();
            int node = curr.second;
            double currProb = curr.first;
            if(currProb < prob[node])continue; 
            if(node == end_node) return currProb;
            // this is for ignoring the outdated value 
            for(auto neigh : adj[node]){
                int neighNode = neigh.first;
                double edge_prob = neigh.second;
                double newProb = currProb * edge_prob;
                
                if(newProb > prob[neighNode]){
                    prob[neighNode] = newProb;
                    st.push({newProb,neighNode});
                }
            }
        }
    return 0;
    }
};
