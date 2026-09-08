/*
// Use stringstream to split the string into individual words.
// 1. Create a stringstream using the given string s.
// 2. Extract one word at a time using ss >> word.
// 3. Store each extracted word in the words vector.
// Example:
// s = "dog cat cat dog"
// words = {"dog", "cat", "cat", "dog"}
//
// Time: O(n)
// Space: O(n)
*/


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        while(ss >> word){
            words.push_back(word);
        }
        unordered_map<char , string> dq;
        unordered_map< string , char> revdq;
        if(pattern.size() != words.size())
            return false;
        for(int i =0 ; i< pattern.size() ; i++){
            if(dq.find(pattern[i]) == dq.end() && revdq.find(words[i]) == revdq.end()){
            dq[pattern[i]] = words[i];
            revdq[words[i]] = pattern[i];
            }
            else{
                if(dq[pattern[i]]!= words[i] || revdq[words[i]]!= pattern[i]) return false;
            }


        }
        return true;
    }
};
