/*Stack → indexes waiting for a warmer day

Current temperature is warmer
        ↓
resolve stack.top()
        ↓
ans[stack.top()] = current_index - stack.top()
        ↓
pop
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            int curr = i;

            while (!s.empty() && temperatures[s.top()] < temperatures[curr]) {

                ans[s.top()] = i - s.top();

                s.pop();
            }

            s.push(curr);
        }
        return ans;
    }
};
