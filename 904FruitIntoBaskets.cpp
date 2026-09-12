```cpp
// Sliding Window + Frequency Array
//
// 1. Use left and right pointers to maintain a sliding window.
// 2. Use count[] to store the frequency of each fruit type in the window.
// 3. Use distinct to track how many different fruit types are currently
//    present in the window.
// 4. When adding fruits[right]:
//    - If its count is 0, it is a new fruit type, so distinct++.
//    - Then increase its frequency.
// 5. If distinct <= 2, the window is valid.
//    Update ans with the current window length.
// 6. If distinct > 2, the window is invalid.
//    - If count[fruits[left]] == 1, removing it will remove that fruit
//      type completely, so distinct--.
//    - Decrease its count and move left forward.
// 7. Move right forward after every iteration.
//
// Time: O(n)
// Space: O(n)
```
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0 ;
        int right = 0; 
        int ans = 0 ; 
        int distinct = 0;
        vector<int> count(fruits.size(),0);
  
        while(right < fruits.size()){
            if(count[fruits[right]] == 0) distinct++;
            count[fruits[right]]++;
   
            if(distinct <= 2){
                ans = max(ans, right - left + 1);
            }
            else{
                if(count[fruits[left]] == 1)
                    distinct--;
                count[fruits[left]]--;

                left++;
            }
            right++;
        }
        return ans;
    }
};
