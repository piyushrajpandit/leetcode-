class Solution {
public:

    unordered_set<string> answer;

    // CHANGE 1:
    // Check whether the current string is valid
    bool valid(string &s) {

        int count = 0;

        for(char c : s) {

            if(c == '(') {
                count++;
            }
            else if(c == ')') {

                count--;

                if(count < 0)
                    return false;
            }
        }

        return count == 0;
    }


    // CHANGE 2:
    // DFS now focuses only on WHICH parentheses to remove
    void dfs(string &s,
             int start,
             int leftRemove,
             int rightRemove) {

        // CHANGE 3:
        // When required removals are complete,
        // check whether the string is valid
        if(leftRemove == 0 && rightRemove == 0) {

            if(valid(s)) {
                answer.insert(s);
            }

            return;
        }


        for(int i = start; i < s.size(); i++) {

            // CHANGE 4:
            // Skip duplicate removal at the SAME level
            if(i > start && s[i] == s[i - 1])
                continue;


            // Remove '('
            if(leftRemove > 0 && s[i] == '(') {

                string next =
                    s.substr(0, i) +
                    s.substr(i + 1);

                dfs(next,
                    i,
                    leftRemove - 1,
                    rightRemove);
            }


            // Remove ')'
            if(rightRemove > 0 && s[i] == ')') {

                string next =
                    s.substr(0, i) +
                    s.substr(i + 1);

                dfs(next,
                    i,
                    leftRemove,
                    rightRemove - 1);
            }
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        answer.clear();

        int leftRemove = 0;
        int rightRemove = 0;


        // CHANGE 5:
        // Find the minimum number of removals
        for(char c : s) {

            if(c == '(') {
                leftRemove++;
            }

            else if(c == ')') {

                if(leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }


        // Start DFS
        dfs(s,
            0,
            leftRemove,
            rightRemove);


        return vector<string>(
            answer.begin(),
            answer.end()
        );
    }
};
