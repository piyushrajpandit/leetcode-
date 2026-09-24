/*
    LeetCode 38 - Count and Say

    Idea:
    Start with "1" and generate the next term by reading the previous term.

    Example:
    1211
    -> one 1, one 2, two 1s
    -> 11 + 12 + 21
    -> 111221

    Logic:
    1. ans = "1" because it is the first term.
    2. Generate the next term n-1 times.
    3. Traverse ans from left to right.
    4. Keep count of consecutive equal digits.
    5. If current digit == next digit:
           count++;
       Otherwise:
           add count + current digit to temp
           reset count = 1
    6. The last group does not have a next digit,
       so add the final count + last digit after the loop.
    7. Set ans = temp and continue.

    Important:
    - Count CONSECUTIVE digits, not total frequency.
    - Use j + 1 only when j is not the last index.
    - count is int, so use to_string(count).
    - ans already starts at term 1, so loop runs n-1 times.

    Pattern:
    Same digit     -> count++
    Different digit -> save count + digit, reset count
    End of string   -> save the last group
*/
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        if( n == 1)
         return "1";
        for(int i =1 ; i< n ; i++){

            string temp  ="";
            int count = 1;

            for( int j = 0 ; j< ans.length()-1; j++){
                
                if( ans[j] == ans[j+1]){
                    count++;
                }
                else{
                    temp = temp + to_string(count) + ans[j];
                    count = 1;
                }

            }
        temp = temp + to_string(count) + ans[ans.length() -1];
        ans = temp;
        }
        return ans;
    }
};
