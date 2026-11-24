class Solution {
public:
    int hammingWeight(int n) {
        int ans =0 ;
        for(int i= 0 ; i <32 ;i++){
            int bit = n&1;
            if(bit == 1)
                ans++;
            n = n>>1;
        }
        return ans;
    }
};
