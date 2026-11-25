class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev= -1;
     
        while(n>0){
            int bit = n&1;
            
            if(bit == prev ){
                return false;
            }
            prev= bit;
            n = n>>1;
        }
        return true;
    }
};
