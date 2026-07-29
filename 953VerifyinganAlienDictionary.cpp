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
//    return true.



class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> rank;
        int i =0; 
        for(char ch : order){
            rank[ch] = i;
            i++;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string first = words[i];
            string second = words[i + 1];

            int len = min(first.size(), second.size());
            bool foundDifference = false;

            // Compare characters one by one
            for (int j = 0; j < len; j++) {
                if (first[j] != second[j]) {
                    if (rank[first[j]] > rank[second[j]])
                        return false;

                    foundDifference = true;
                    break;
                }
            }
             if (!foundDifference && first.size() > second.size())
                return false;
        }
        return true;
      
    }
};

  
