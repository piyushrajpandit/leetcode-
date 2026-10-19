/*
LeetCode 93: Restore IP Addresses

Approach: Backtracking

1. Divide the string into exactly 4 segments.
2. Each segment must contain 1 to 3 digits.
3. Reject segments with leading zeros, such as "01".
4. Convert each segment to an integer and reject values greater than 255.
5. Use recursion to try every valid segment length.
6. If 4 segments use all digits, add the IP address to the answer.
7. Remove the last dot before storing the valid IP address.
8. Return all valid IP addresses.

Time Complexity: O(1) for the fixed maximum of 12 digits.
Space Complexity: O(1) auxiliary space, excluding the output.
*/

class Solution {
public:
    void backtrack(string s ,vector<string>& answer,int index,  string temp,int parts ){

        if(parts == 4 && index == s.size()){
            temp.pop_back();
            answer.push_back(temp);
            return ;
        }
        if(parts == 4 || index == s.size()){
            return ;
        }
      
        for(int len = 1; len <= 3 && index + len <= s.size(); len++){
            string part = s.substr(index, len);
            if(len > 1 && part[0] == '0'){
                break;
            }
            int number = stoi(part);
            if(number > 255){
                break;
            }
            backtrack(s,answer, index+ len, temp+ part+".", parts+1);
        }

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> answer;
        if(s.size() < 4 || s.size() > 12){
            return answer;
        }
        backtrack(s,answer,0, "" ,0);
        return answer;
    }
};
