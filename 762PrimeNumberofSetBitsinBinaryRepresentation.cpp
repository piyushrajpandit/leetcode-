class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int answer = 0;
        for(int i =left ; i<= right; i++){
            int temp= i;
            int count = 0;
            while(temp > 0){
                int bit = temp & 1;
               
                if(bit ==1){
                    count++;
                }
                temp = temp>>1;

            }
            if(count == 2 || count == 3 || count == 5 ||
               count == 7 || count == 11 ||
               count == 13 || count == 17 ||
               count == 19){
                answer++;
            }
        }
        return answer;
    }
};
