class Solution {
public:
    bool canAliceWin(int n) {
        bool aliceturn = true;
        int remove = 10;
        while(n > 0){
            if(n < remove) return !aliceturn;
           
            n = n - remove;
            remove = remove -1;
            aliceturn = !aliceturn;
        }
        return !aliceturn;
    }
};
