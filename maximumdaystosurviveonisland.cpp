// this is the question for to find in limited resources how much day a person can survive on island
/*
===========================================================================
POSSIBLE TO SURVIVE ON ISLAND (Greedy)

Problem:
A person has to survive for S days.
- Can buy at most N units of food per day.
- Needs M units of food each day.
- Shop is closed every Sunday.

Find the minimum number of days required to buy food.
If survival is impossible, return -1.

Greedy Idea:
1. Count the number of Sundays.
2. Compute the number of days the shop is open (buying days).
3. Calculate the total food needed for survival.
4. Find the minimum buying days required to purchase that food.
5. If required buying days <= available buying days, survival is possible.
   Otherwise, return -1.

Formula:
Sundays          = S / 7
Buying Days      = S - Sundays
Total Food       = S * M
Min Buying Days  = ceil((S * M) / N)

Special Case:
If daily requirement (M) is greater than the maximum food purchasable
per day (N), survival is impossible (except when S = 1).

Time Complexity : O(1)
Space Complexity: O(1)

Greedy Pattern:
Calculate total resource needed.
Calculate maximum resource that can be obtained.
Compare required days with available buying days.

===========================================================================
*/
class solution{
public:
int minimumDays(int S, int N, int M){
  int sunday = S/7;

  int buyingDays = S - sunday ;
int totalFood = S*M;
if(totalfood %N ==0){
ans = totalFood \N;
}
else{
ans  = totalFood /N +1;
}
if(ans <= buyingDays)
    return ans;
else
  return -1;
}
