class Solution {
public:
    int balancedStringSplit(string s) {
      
        int count_left =0 ;
        int count_right = 0;
        int answer = 0;
    
            for(int i = 0; i< s.size() ; i++){
                if(s[i] == 'L'){
                    count_left++;
                }
                else{
                    count_right++;
                }
                if(count_left == count_right){
                   
                    answer++;

                }
            }
       
        
        return answer;
    }
};
