class Solution {
public:
  
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int answer = 0;
        for(int i =0 ;i< coins.size() ;i++){
            if(coins[i] > answer+1){
                break;
            }
            answer += coins[i];
        }
        return answer +1;
    }
};
