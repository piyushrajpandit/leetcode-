// in this question we have to make all fraction whose denominator is grater and numberato 

//   if(_set.find(fraction )== _set.end()){
// this is the line we have to check set.find finds fraction and if not found mive to next part and if nothing it return _set.end()
// if fraction find it return iteration to that point 
// and not found return _set.end()
//   _set.end()
// Represents a position after the last element.
// Think of it as: “search failed”.

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> result;
        unordered_set<float> _set;

        for(int i =1; i<n; ++i){
            for(int j = i+1; j<=n; ++j){
                float fraction = float(i)/j;
                if(_set.find(fraction )== _set.end()){
                    result.push_back(to_string(i) + "/"+ to_string(j));
                    _set.insert(fraction);
                }
            }
        }
        return result;
    }
};
