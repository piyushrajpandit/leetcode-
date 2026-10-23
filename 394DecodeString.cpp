class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;

        string curr= "";
        int num = 0;
       
        for(int i =0 ; i< s.size(); i++){
            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == '['){
             nums.push(num);
             strs.push(curr);
             num= 0;
             curr= "";
            }
            else if(s[i] == ']'){
                int k = nums.top();
                nums.pop();
                string temp = curr;
                for(int j =1 ;j< k ;j++){
                    curr += temp;

                }
                curr = strs.top() + curr;
                strs.pop();
            }
            else{
                curr  += s[i];
            }
                
            }
