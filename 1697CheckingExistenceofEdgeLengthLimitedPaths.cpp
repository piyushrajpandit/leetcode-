// Approach:
// 1. Store each edge as {u, v, originalIndex, weight}.
// 2. Store each query as {source, destination, originalIndex, limit}.
// 3. Sort edges by weight and queries by limit.
// 4. Maintain a DSU and an edge pointer `i`.
// 5. For each query (in increasing order of limit):
//      - Union all edges with weight < current query's limit.
//      - Check if source and destination belong to the same component.
//      - Store the result at the query's original index.
// 6. Return the results in the original query order.
//
// Time Complexity: O((E + Q) log(E + Q) + (E + Q) * α(N))
// Space Complexity: O(N + E + Q)
//
// Key Insight:
// Since query limits are processed in increasing order, edges are only added
// to the DSU once. Connectivity for each query is then checked using find().

class Solution {
public:
    vector<int> parent;
    int find(int i){
        if(parent[i] == i )
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j){
        int rootI = find(i);
        int rootJ = find(j);
        if(rootI != rootJ)
            parent[rootJ] = rootI;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> result(queries.size());
        parent.resize(n);
        for(int i= 0 ; i< n; i++){
            parent[i] = i;
        }
        
        vector<vector<int>> edgenew;
        vector<vector<int>> query;
        for(int i= 0 ; i< edgeList.size(); i++){
            vector<int> line(4);
            line[0] = edgeList[i][0];
            line[1] = edgeList[i][1];
            line[2] = i;
            line[3] = edgeList[i][2];
            edgenew.push_back(line);

        }
          for(int i= 0 ; i< queries.size(); i++){
            vector<int> line(4);
            line[0] = queries[i][0];
            line[1] = queries[i][1];
            line[2] = i;
            line[3] = queries[i][2];
            query.push_back(line);

        }
        sort(edgenew.begin(), edgenew.end(),
        [](const vector<int>& a, const vector<int>& b){
            return a[3] < b[3];
        });
        sort(query.begin(), query.end(),
        [](const vector<int>& a, const vector<int>& b){
            return a[3] < b[3];
        });
        int i= 0;
        for(int j =0 ; j< query.size(); j++){
            while(i < edgenew.size() && edgenew[i][3] < query[j][3] ){
                unite(edgenew[i][0],edgenew[i][1]);
                i++;
            }
        int u = query[j][0];
        int v = query[j][1];
        result[query[j][2]] = (find(u) == find(v));
        }
       
        return result;
    }
};
