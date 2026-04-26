// #appraoch 
// how to do it we have to go through each string and create a mapping with it 
// an generate a unordered map first we generate a key and second we have that string so when we we start we push all same key in result and then then other same key in result 


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> result;
       if(strs.size()==0){
        return result;
       }
       unordered_map<string , vector<string>> map ;
       for(string s: strs){
        string key = s;
        std::sort(key.begin(), key.end());
        map[key].push_back(s);
       }
        for(auto pair : map){
            result.push_back(pair.second);
        }
        return result ;
    }
};
