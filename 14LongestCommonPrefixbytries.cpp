// # approach 
// first thing is vector<string> strs = {"apple", "banana", "cat"}; looks like this 
//   so make first string first character and then match it with all the other string characters if it matches then go forward else break the loop
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for(int i =0 ; i < strs[0].length() ; i++){
            char ch = strs[0][i];
        
        bool match = true;
        //for comparing string with rest of string 
        for(int j=0 ; j< n ; j++){
            //not match
            if(i >= strs[j].size()  || ch!= strs[j][i]){
                match = false;
                break;
            }
        }
        
        if(match == false){
            break;
        }
        
            ans.push_back(ch);
        
        }
        return ans;
    }
};
