/*
    LeetCode 30 - Substring with Concatenation of All Words

    Approach: Sliding Window + Hash Maps

    1. All words have the same length, so process the string in
       chunks of `wordlen`.

    2. `required` stores the required frequency of every word.

    3. Try every possible starting offset from 0 to wordlen - 1.
       This ensures every possible word alignment is checked.

    4. For each offset:
       - `left`  = start of current window
       - `right` = end/current word position
       - `window` = frequency of words currently in the window
       - `count` = number of words currently in the window

    5. Extract one word at a time using:
           s.substr(right, wordlen)

    6. If the word is NOT in `required`:
       - Clear the current window
       - Reset count
       - Move left after this invalid word

    7. If the word is valid:
       - Add it to `window`
       - Increment count

    8. If a word appears more times than required:
       Keep removing words from the left until its frequency
       becomes valid again.

    9. If `count == wordcount`, the window contains exactly
       all required words, so store `left` in the answer.

    10. Move `right` by `wordlen` each time because we process
        one complete word at a time.

    Key idea:
        required -> what we NEED
        window   -> what we CURRENTLY HAVE
        count    -> number of words currently in the window

    Time Complexity: O(n * wordlen) approximately
    Space Complexity: O(number of distinct words)
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordlen = words[0].length();
        int wordcount = words.size();
        vector<int> ans;
        if(wordlen * wordcount > s.length())   
            return {};
        unordered_map<string, int> required;
        for(int i =0 ; i< words.size() ; i++){
            required[words[i]]++;
        }

        for(int offset = 0 ; offset< wordlen ; offset++){
            int left =offset ; 
            int right =offset ;
            int count = 0;
            unordered_map<string , int > window;

            while(right + wordlen <= s.length()){
                string word = s.substr(right, wordlen);
             
                if(required.find(word) == required.end()){
                    window.clear();
                    count = 0 ;
                    left = right + wordlen;
                }
                else{
                    window[word]++;
                    count++;
                    while(window[word] > required[word]){
                        string leftWord = s.substr(left, wordlen);
                        window[leftWord]--;
                        count--;
                        left+= wordlen;
                    }
                    if(count == wordcount){
                        ans.push_back(left);
                    }
                }
                right = right + wordlen;
            }
        }
        
        return ans;
    }
};
