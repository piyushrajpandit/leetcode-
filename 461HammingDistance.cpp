class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans= 0;
        for(int i =0 ; i< 32; i++){
            int bit1 = x&1;
            int bit2 = y&1;
            if(bit1 != bit2){
                ans++;
            }
            x = x>>1;
            y = y>>1;
        }
        return ans;
    }
};
