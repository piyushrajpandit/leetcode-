class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a > 0 || b > 0|| c > 0){
            int abit = a&1;
            int bbit = b&1;
            int cbit = c&1;
            if((abit | bbit)!= cbit){
                ans++;
                if(abit ==1 && bbit ==1 && cbit ==0) ans++;
            }
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        return ans;
    }
};
