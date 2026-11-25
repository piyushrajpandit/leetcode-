class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int distance=0;
        int answer = -1;
        int pos = 0 ;
        while(n > 0){
            int bit = n&1;
            if(bit ==1){
                if(prev != -1){
                    distance = pos - prev;
                    answer = max(answer, distance);
                }
                prev = pos;
            }
            pos++;
            n = n>>1;
        }
        if(answer == -1){
            return 0;
        }
        return answer;
    }
};
