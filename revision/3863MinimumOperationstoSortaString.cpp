// If the string is already sorted, answer is 0.
// If the string has length 2 and is unsorted, answer is -1.
// If the first character is the maximum AND the last is the minimum,
// we need 3 operations to sort the string.
// If the first character is the minimum OR the last is the maximum,
// we need only 1 operation.
// Otherwise, we need 2 operations because we can sort a substring
// to fix the misplaced minimum/maximum, then sort the remaining part.
// So, the maximum answer is 3, not 2, because the special case
// (maximum at the start and minimum at the end) needs 3 operations.


class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(s.begin(), s.end()))
            return 0;
        if(n == 2 ) {
            return -1;
        }
        char mn =*min_element(s.begin(), s.end());
        char mx =*max_element(s.begin(), s.end());

        if(s[0] == mx && s[n-1] == mn && s.find(mn) == n-1 && s.rfind(mx) == 0)
            return 3;
        if(s[0] == mn || s[n-1] ==mx)
            return 1;
       
        return 2;
    }
};
