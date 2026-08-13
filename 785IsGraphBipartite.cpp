
// Summary:
//
// 1. Store the rank (position) of each character in the alien alphabet
//    using a hash map.
//
// 2. Compare every adjacent pair of words.
//
// 3. Compare the characters of both words from left to right.
//
// 4. At the first different character:
//      - If the first character has a greater rank than the second,
//        the words are not sorted, so return false.
//      - Otherwise, move to the next pair of words.
//
// 5. If all compared characters are the same, the shorter word
//    should come first. If the first word is longer, return false.
//
// 6. If every adjacent pair satisfies the alien dictionary order,
//    return true.class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
       
        vector<int> color(graph.size() , -1);
        queue<int> q;
        
        for(int i = 0 ; i< graph.size(); i++){
            if(color[i] == -1 ){
                color[i] =1 ;
                q.push(i);
                    while(!q.empty()){
                        int temp = q.front();
                        q.pop();
                        for(auto next : graph[temp]){
                            if(color[next] == -1 ){
                                color[next] = 1 - color[temp];
                                q.push(next);
                            }
                            else if (color[next] == color[temp]){
                                return false;
                            }
                        }
                }
            }
        }
        return true;
    }
};
