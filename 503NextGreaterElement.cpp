
// Monotonic Stack + Circular Array approach
// 1. Traverse the array twice to handle the circular nature of the array.
// 2. Use i % n to get the circular index.
// 3. Store indexes in the stack, not values.
// 4. If the current element is greater than the element at stack.top(),
//    it is the next greater element for that index.
// 5. Update ans[stack.top()] and pop the index.
// 6. Initialize ans with -1 for elements that have no greater element.
// 7. Push indexes only during the first pass to avoid duplicates.
//
// Time: O(n)
// Space: O(n)
```
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size() ,-1);

        for(int i =0 ; i< 2*nums.size() ;i++){
            int curr = i%nums.size();
            while( !s.empty() && nums[s.top()] < nums[curr]){
                ans[s.top()] = nums[curr];
            s.pop();
            }
            if(i< nums.size()){
                s.push(curr);
            }
        }
return ans;
    }
};
