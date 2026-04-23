// this in not stock market proce if stock goes down mark is buy it going up then leave it until first dip after first dip make the prevoius one buy 
// and at last iteration also return profit 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int buy= prices[0];
        int profit =0 ;
        for(int i= 1 ; i< prices.size() ; ++i){
            if(prices[i] < prices[i-1] ){//price drop
                profit += prices[i-1] - buy;
                buy = prices[i];

            }
        }
        profit+= prices.back()  - buy;
        return profit ;
    }
};
