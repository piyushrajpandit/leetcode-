
/*
LeetCode 301 - Remove Invalid Parentheses
------------------------------------------

GOAL:
    Remove the minimum number of '(' or ')' so that the string becomes valid.
    Return ALL possible valid strings.

STEP 1: Find minimum removals
------------------------------
Use leftRemove and rightRemove.

For every '(':
    leftRemove++

For every ')':
    if(leftRemove > 0)
        match it with an existing '(' -> leftRemove--
    else
        this ')' has no matching '(' -> rightRemove++

After this:
    leftRemove  = extra '(' that must be removed
    rightRemove = extra ')' that must be removed


STEP 2: DFS / BACKTRACKING
--------------------------
At every character we have two choices:

    1. REMOVE it
    2. KEEP it

For '(':
    If leftRemove > 0:
        We can remove it.
        leftRemove--

    We can also keep it:
        leftCount++


For ')':
    If rightRemove > 0:
        We can remove it.
        rightRemove--

    We can keep it ONLY when:
        leftCount > rightCount

    Why?
        We cannot have more ')' than '(' at any point.

For normal characters:
    Always keep them.
    They don't affect parenthesis balance.


STEP 3: BASE CASE
-----------------
When:

    index == s.size()

We have processed the entire string.

Only accept the string when:

    leftRemove == 0
    rightRemove == 0

Then:
    answer.push_back(current)


IMPORTANT VARIABLES
-------------------
index:
    Current position in the original string.

leftRemove:
    Number of '(' still required to remove.

rightRemove:
    Number of ')' still required to remove.

leftCount:
    Number of '(' kept in current.

rightCount:
    Number of ')' kept in current.

current:
    String we are building.

answer:
    Stores all valid results.


DFS MENTAL MODEL
----------------

For every parenthesis:

                 current char
                     |
              ----------------
              |              |
            REMOVE          KEEP
              |              |
        reduce removal    update count


For '(':
    REMOVE -> leftRemove - 1
    KEEP   -> leftCount + 1

For ')':
    REMOVE -> rightRemove - 1
    KEEP   -> only if leftCount > rightCount
              then rightCount + 1


WHY leftCount > rightCount?
--------------------------------
Example:

    "())"

After keeping "()":

    leftCount  = 1
    rightCount = 1

Next ')' cannot be kept because:

    1 > 1  -> false

So it must be removed.

This prevents invalid strings such as:

    ")("
    "())"
    "))(("


IMPORTANT C++ DETAILS
---------------------
answer should be a CLASS MEMBER because dfs() needs to access it.

C++ is case-sensitive:
    rightCount != rightcount
    current != courrent

At the end, duplicate results may exist.
Use:

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

to remove duplicates.
*/class Solution {
public:
vector<string> answer;
    void dfs(string s, int index ,int leftRemove, int rightRemove,int leftCount , int rightCount, string current ){
        
        if(index == s.size()){
            if(leftRemove ==0 && rightRemove == 0){
                answer.push_back(current);
            }
            return ;
        }
        char c = s[index];
        if(c== '(' && leftRemove > 0){
            dfs(s, index+1, leftRemove -1, rightRemove, leftCount , rightCount , current);
        }
         if(c == ')' && rightRemove > 0) {

            dfs(s, index + 1,
                leftRemove,
                rightRemove - 1,
                leftCount,
                rightCount,
                current);
        }
        if( c!= '(' && c != ')'){
            dfs(s, index+1, leftRemove , rightRemove, leftCount , rightCount , current +c);

        }
        else if( c == '('){
            dfs(s , index+1, leftRemove, rightRemove, leftCount+1, rightCount , current + c);
        }
        else if(c == ')'){
            if(leftCount > rightCount){
                dfs(s ,index +1, leftRemove, rightRemove ,leftCount , rightCount+1, current + c);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
       int leftRemove =0;
       int rightRemove = 0;
       for(char c : s){
            if(c== '('){
                leftRemove++;
            }
            else if( c == ')'){
                if(leftRemove > 0){
                    leftRemove--;
                }
                else{
                    rightRemove++;
                }
            }
       }
       
       dfs(s, 0, leftRemove, rightRemove, 0,0,"");
        sort(answer.begin(), answer.end());
        answer.erase(unique(answer.begin(), answer.end()), answer.end());
        return answer;
      
        
    }
};
