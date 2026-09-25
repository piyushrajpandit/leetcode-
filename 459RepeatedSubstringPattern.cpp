// Approach:
// 1. Store the length of the string and find all possible pattern lengths
//    from 1 to length/2 that completely divide the string length.
// 2. For each possible length, take the first part of the string as the pattern.
// 3. Check the entire string using j % pattern_length so the pattern repeats
//    cyclically across the string.
// 4. If every character matches the repeating pattern, return true.
// 5. If no possible pattern works, return false.
//
// Example: "ababab"
// Pattern length = 2 → "ab"
// j % 2 gives: 0,1,0,1,0,1 → "ababab" → valid.
//
// Time: O(n²)
// Space: O(n)

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int length = s.size();
        vector<int> pos_len;
        for(int i =1 ; i<= length/2;i++){
            if(length % i == 0){
                pos_len.push_back(i);
            }
        }
        for(int i =0 ; i< pos_len.size() ; i++){
            string pattern = s.substr(0, pos_len[i]);

            bool valid = true;
            for( int j =0 ; j< length; j++){

                if(s[j] != pattern[j % pos_len[i]]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                return true;
            }
        }
        return false;
    }
};
