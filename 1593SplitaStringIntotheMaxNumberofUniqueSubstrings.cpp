/*
LeetCode 1593 - Split a String Into the Max Number of Unique Substrings

We use BACKTRACKING to try every possible way of splitting the string.

* `used` is a set that stores all substrings selected in the current split.
* `index` tells us where the next substring should start.
* `count` tells us how many unique substrings we have selected so far.
* `ans` stores the maximum number of unique substrings found.

Inside `solve()`:

1. BASE CASE:
   If `index == s.size()`, we have reached the end of the string,
   so the current split is complete. Update `ans` with `count`.

2. TRY EVERY POSSIBLE SUBSTRING:
   Starting from `index`, move `i` from `index` to the end of the string.
   `s.substr(index, i - index + 1)` creates every possible substring
   starting at `index`.

3. CHECK UNIQUENESS:
   `used.find(substring) == used.end()` means the substring has not
   been used before, so we are allowed to choose it.

4. CHOOSE:
   Add the substring to `used`.

5. RECURSE:
   Call `solve()` with:

   * `count + 1` because we selected one more substring.
   * `i + 1` because the next substring must start after the current one.

6. UNDO / BACKTRACK:
   After the recursive call finishes, remove the substring using
   `used.erase(substring)`.
   This allows us to try a different substring from the same position.

The overall pattern is:

Choose substring
↓
Check if unique
↓
Add it to set
↓
Recursively solve remaining string
↓
Remove it from set (backtrack)
↓
Try another substring

Important:
Use `count + 1`, not `count++` in the recursive call.
`count++` passes the old value first, while we need the increased count.
*/


class Solution {
public:
    int ans = 0;
    void solve(string s, set<string>& used,int count , int index){
    
            if(index == s.size()){
                ans = max( count , ans);
                return;
            }
            for(int i = index ; i< s.size() ;i++){
                string substring = s.substr(index, i -index + 1);

                if(used.find(substring) == used.end()){
                    used.insert(substring);
                    
                    solve(s, used,count+1, i+ 1);
                    used.erase(substring);

                }    

            }
        }
    
    int maxUniqueSplit(string s) {
        set<string> used;
      
        solve(s, used,0,0);
        
        return ans;
    }
};
