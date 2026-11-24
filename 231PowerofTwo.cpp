class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <=0) return false;
        int count = 0;
        for(int i =0 ; i< 32 ;i++){
            int bit = n&1;
            if(bit ==1){
                count++;
                if(count >1){
                    return false;
                }
            }
            n =n>>1;
        }
        return true;
    }
};
