
/*
for every flower
       ↓
Has it bloomed by mid?
       ↓
   YES       NO
    ↓         ↓
count it    reset count
    ↓
reached k?
    ↓
   YES
    ↓
make bouquet
    ↓
reset count
*/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m* k > bloomDay.size())
            return -1;
        int left = 1;
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while(left < right){
            int mid = left + (right - left )/2;
          
            int consecutive = 0;
            int bouquets = 0;
            for(auto day : bloomDay){
                
                 if(day <= mid){
                    consecutive++;
                    if(consecutive == k){
                        bouquets++;
                        consecutive = 0;
                    }
                 }
                 else{
                    consecutive = 0;
                 }
            }

        if( bouquets >= m ){
            right = mid;
        }
        else{
            left = mid + 1;
        }
        }
        return left;
    }
};
