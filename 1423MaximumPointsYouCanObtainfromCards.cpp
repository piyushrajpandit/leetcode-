/*
    LeetCode 1423 - Maximum Points You Can Obtain from Cards

    Approach: Fixed-Size Sliding Window

    Key observation:
    We need to TAKE exactly k cards from either the left or right.

    Instead of finding the maximum sum of k cards,
    find the minimum sum of the cards we DON'T take.

    Number of cards NOT taken:
        windowSize = n - k

    Since the cards not taken must be in the middle,
    they form one continuous subarray of size n-k.

    Therefore:
        answer = totalSum - minimumWindowSum

    Steps:
    1. Calculate totalSum of all cards.

    2. Calculate:
           windowSize = n - k

    3. Find the sum of the first window of size n-k.

    4. Slide the fixed-size window:
           remove cardPoints[left]
           move left
           add cardPoints[right]
           move right

    5. Keep track of the minimum window sum.

    6. Return:
           totalSum - minimumWindowSum

    Important:
    - This is a FIXED-SIZE sliding window.
    - Window size always remains n-k.
    - Initialize minimum window sum using the first window's sum,
      NOT 0.

    Example:
        cardPoints = [1,2,3,4,5,6,1]
        k = 3

        n = 7
        windowSize = 7 - 3 = 4

        Minimum window:
            [1,2,3,4] = 10

        totalSum = 22

        answer = 22 - 10 = 12

    Time Complexity: O(n)
    Space Complexity: O(1)
*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left =0 ;
        int sum =0 ;
        int right;
        int totalSum = 0;
        int windowSize = cardPoints.size() - k;
        for(int i =0 ; i < cardPoints.size() ;i++){
            totalSum += cardPoints[i];
        }
        for(int right = 0; right < windowSize ; right++ ){
            sum += cardPoints[right];

        }
        int ans = sum;
        right = windowSize ;
        while(right < cardPoints.size()){
            sum -= cardPoints[left];
            left++;
            sum+= cardPoints[right];
            right++;
            ans = min ( ans, sum);

        }
    return totalSum - ans;

    }
};
