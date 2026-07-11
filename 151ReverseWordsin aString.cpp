/*
================== Reverse Words in a String ==================

Problem:
Given a string, reverse the order of words while removing
leading, trailing, and extra spaces.

Approach:
1. Traverse the string from right to left.
2. Store characters of the current word in 'temp'.
3. When a space is encountered:
   - If temp is not empty:
       • Reverse temp (since characters were collected backwards).
       • Append the word to the answer.
       • Add a single space.
       • Clear temp for the next word.
4. After the loop, append the first word (if any).
5. Remove the extra trailing space from the answer.

Key Idea:
- Traverse from the end to naturally obtain words in reverse order.
- Ignore consecutive spaces using:
      if (!temp.empty())
- Reverse each collected word before appending.

Example:
Input : "  hello   world  "
Output: "world hello"

Time Complexity : O(n)
Space Complexity: O(n)

Pattern:
Traverse Right -> Left
Collect Word -> Reverse Word -> Append to Answer
Ignore Extra Spaces -> Remove Final Space
*/

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        for(int i = s.length()-1 ; i>= 0 ; i--){
            if(s[i] == ' '){
                if(!temp.empty()){
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                ans.push_back(' ');
                temp = "";
            }
            }
            else{
                temp.push_back(s[i]);
            }
        }
        if(!temp.empty()){
        reverse(temp.begin(), temp.end());
        ans = ans + temp;
        }
        if (!ans.empty() && ans.back() == ' ')
        ans.pop_back();
        return ans;
    }
};
