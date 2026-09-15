class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0;
        int right = 0;
        int countTrue = 0;
        int countFalse = 0;
        int ans = 0;
        while(right < answerKey.size()){
            if(answerKey[right] == 'T')countTrue++;
          
            
       
            while(countTrue > k){
                if(answerKey[left] == 'T') countTrue--;
                left++;
            }
            ans = max( ans, right-left +1);
           right++;

        }
        left = 0;
        right = 0;
        while(right < answerKey.size()){
            if(answerKey[right] == 'F')countFalse++;
            while(countFalse > k){
                if(answerKey[left] == 'F') countFalse--;
                left++;
            }
            ans = max( ans, right-left +1);
           right++;
           

        }
        return ans;

    }
};
