// Use two maps to maintain a one-to-one mapping between characters of s and t.
// dq maps: s character -> t character.
// dqrev maps: t character -> s character.
//
// For every position:
// 1. If neither character has been mapped, create the mapping in both maps.
// 2. If a mapping already exists, verify that both mappings match.
// 3. If either mapping is different, the strings are not isomorphic.
//
// Example: "egg" -> "add"
// e -> a
// g -> d
//
// Two maps are necessary to prevent cases like "ab" -> "cc",
// where two different characters map to the same character.
//
// Time: O(n)
// Space: O(1), since there are at most 256 possible characters.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> dq;
        unordered_map<char, char > dqrev;

        for(int i =0 ; i< s.length() ; i++){
            if(dq.find(s[i]) == dq.end() && dqrev.find(t[i]) == dqrev.end()){
                dq[s[i]] = t[i];
                dqrev[t[i]] = s[i];
            }
            else{
                if(dq[s[i]] != t[i] || dqrev[t[i]] != s[i]) 
                return false;
            }
        }
        return true;
    }
};
