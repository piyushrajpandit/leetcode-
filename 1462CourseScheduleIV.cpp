// LeetCode 1462 - Course Schedule IV
//
// Approach: Floyd-Warshall / Transitive Closure
//
// 1. Create a boolean matrix `reach`.
//    reach[u][v] = true means course u is a prerequisite
//    of course v.
//
// 2. For every direct prerequisite [u, v]:
//       reach[u][v] = true;
//
// 3. Find indirect prerequisites using Floyd-Warshall:
//       If i can reach k AND k can reach j,
//       then i can reach j.
//
//       reach[i][j] = true
//       if reach[i][k] && reach[k][j]
//
// 4. For every query [u, v]:
//       reach[u][v] tells whether u is a prerequisite of v.
//
// 5. Store the result of every query in `ans`.
//
// Time Complexity: O(n^3 + prerequisites.size() + queries.size())
// Space Complexity: O(n^2)

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<bool>> reach(numCourses , vector<bool> (numCourses, false));
        for(int i =0 ; i< prerequisites.size(); i++){
                int u = prerequisites[i][0];
                int v = prerequisites[i][1];
                reach[u][v] = true;
            
        }
        for(int k =0; k < numCourses; k++){
            for(int i =0 ; i< numCourses; i++){
                for(int j = 0 ; j < numCourses ; j++){
                    if(reach[i][k] == true && reach[k][j] == true)
                        reach[i][j] = true;
                }
            }
        }
        for(auto next : queries){
            int i = next[0];
            int j = next[1];
            ans.push_back(reach[i][j]);
        }
        return ans;
    }
};
