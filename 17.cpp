class Solution {

public:
void  solve(string digits,vector<string>& ans,int  index,string output, string mapping[]) {
    //base case 
    if(index >= digits.size()){
        ans.push_back(output);
        return ; 

    }

    //normal recurssion tree
    int number = digits[index]- '0';
    string value = mapping[number];
    for (int i =0 ; i < value.length(); i++){
        output.push_back(value[i]);
        solve(digits, ans, index +1, output,mapping);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans ;
        if(digits.length()==0)
        return ans ;
        string output;
        int index = 0 ; 
        string mapping[10]= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, ans, index, output,mapping);
        return ans;
        
    }
};
