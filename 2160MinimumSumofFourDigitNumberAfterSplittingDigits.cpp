class Solution {
public:
    int minimumSum(int num) {
        int digit;
        vector<int> v1;
        vector<int> v2;
        vector<int> number;
        while(num > 0){
            digit = num % 10;
            num /= 10;
            number.push_back(digit);
        }
        sort(number.begin(), number.end());
        int i =0; 
        while(i< number.size()){
            v1.push_back(number[i]);
            i++;
            if(i < number.size()){
            v2.push_back(number[i]);
            i++;
            }
        }
        int ans1 = 0;
        for(int i =0 ; i< v1.size() ; i++){
            ans1 = ans1 * 10 + v1[i];
        }
        int ans2 = 0;
        for(int i=0; i < v2.size(); i++){
            ans2 = ans2 * 10 + v2[i];
        }
        return ans1 + ans2 ;
    }
};
