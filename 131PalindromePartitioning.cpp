/*1. If start reaches the end
      ↓
   Current partition is complete
      ↓
   Put current into answer
      ↓
   return

2. Try every possible substring
   starting from start
      ↓
3. Check if that substring is palindrome
      ↓
4. If palindrome:
      ↓
   Add it to current
      ↓
   Recursively solve the remaining string
      ↓
   Remove it from current (backtrack)
      ↓
5. Try the next substring
*/
class Solution {
public:
    bool palidrom (string s, int left , int right){
      
        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
    void solve(string s, int start ,vector<string> &current , vector<vector<string>> & answer){
        if(start == s.size()){
            answer.push_back(current);
            return ;
        }
        for( int right = start ; right < s.size() ; right++){
            if(palidrom(s,start, right)){
                current.push_back(s.substr(start ,right - start+ 1));
                solve(s, right+ 1, current ,answer);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> current;
        solve(s, 0, current, answer);
        return answer;
    }
};
