erase(starting_index, number_of_characters_to_remove)
            class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> nums;
        stack<int> index;
        string answer;

        for(int i =0 ;i< n;i++){
            while(!nums.empty() && k > 0 && nums.top()> num[i] - '0'){
                nums.pop();
                k--;
            }
            nums.push(num[i] - '0');
            
        }
        while(k > 0 && !nums.empty()){
            nums.pop();
            k--;
        }
        while(!nums.empty()){
            int temp = nums.top();
            nums.pop();
            answer += temp + '0';
        }
        reverse(answer.begin(), answer.end());
        while(answer.size() > 1 && answer[0] == '0'){
            answer.erase(0,1);
        }
        if(answer.empty())
            return "0";
        return answer;
    }
};
        
        return curr;
    }
};
