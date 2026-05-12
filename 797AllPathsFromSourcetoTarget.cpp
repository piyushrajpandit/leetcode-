// #apprach 
// here you have to simple dfs traversal 
// base case is node == graph.size()-1 we have to push path in answer and empty the path vector 
// else call dfs paths for neighbour 
// at last path.pop_back;

class Solution {
public:
   void dfspaths(int node,
                   vector<vector<int>>& graph,
                   vector<int>& path,
                   vector<vector<int>>& ans) {

                    path.push_back(node);

        //target reached 
        if(node == graph.size() -1){
            ans.push_back(path);
            path.pop_back();
            return ;
        }

    for (auto neighbour : graph[node]) {

                dfspaths(neighbour,graph,path,ans);

        }
    path.pop_back();
}

 

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector< int>> ans;
        dfspaths(0,graph, path, ans);
        return ans;
    }
};

