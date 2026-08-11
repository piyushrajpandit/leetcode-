// LeetCode 1436 - Destination City
//
// Approach: Outdegree using unordered_map
//
// 1. Store the outdegree of every city in an unordered_map.
//
// 2. For every path u -> v:
//      - Increase outdegree[u] because u has an outgoing edge.
//      - Add v to the map with value 0 if it is not already present.
//
// 3. The destination city has no outgoing edge,
//    so its outdegree will be 0.
//
// 4. Traverse the map and return the city whose outdegree is 0.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> outdegree;
        for(int i =0 ; i< paths.size(); i++){
            string u = paths[i][0];
            string v = paths[i][1];
            outdegree[u]++;
            if(outdegree.find(v) == outdegree.end())
                outdegree[v] = 0;
        }
        for(auto node : outdegree){
            string city = node.first;
            int out = node.second;
            if(out == 0)
                return city;
        }
        return "";
    }
};
