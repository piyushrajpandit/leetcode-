/*

                 candidate speed
                       ↓
                    mid = ?
                       |
              calculate hours
                 /           \
                /             \
       hours <= h             hours > h
          ↓                       ↓
      speed works             speed too slow
          ↓                       ↓
   maybe smaller speed       need bigger speed
          ↓                       ↓
      right = mid          left = mid + 1
speed:    1  2  3  4  5  6  7  ...
works?:   ❌  ❌  ❌  ✅  ✅  ✅  ✅
so we use binary search 
*/


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left < right) {

            int mid = left + (right - left) / 2;

            long long hours = 0;

            for(auto pile : piles) {
                hours += (pile + mid - 1) / mid;
            }

            if(hours <= h) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};
