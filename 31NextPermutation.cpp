/*
    LeetCode 31 - Next Permutation

    Goal:
    Find the next lexicographically greater permutation.
    If no greater permutation exists, return the smallest permutation.

    Example:
        1 2 5 4 3
        ↓
        1 3 2 4 5


    STEP 1: Find the first decreasing element from the right

        Start from n-2 and find:

            nums[i] < nums[i+1]

        This is the position that we need to increase.

        Example:
            1 2 5 4 3
              ↑
            firstdec = 1   (nums[1] = 2)

        Why from the right?
        The suffix after this position is already in descending order.


    STEP 2: Handle completely decreasing array

        If firstdec == -1:

            3 2 1

        There is no bigger permutation.
        So reverse the entire array:

            1 2 3

        Then return.


    STEP 3: Find the smallest number greater than nums[firstdec]

        Search from the right and find the first:

            nums[i] > nums[firstdec]

        Because the suffix is descending, the first such
        element from the right is the smallest element
        greater than nums[firstdec].

        Example:
            1 2 5 4 3
              ↑     ↑
              2     3

        Swap them:

            1 3 5 4 2


    STEP 4: Reverse the part after firstdec

        The suffix is still in descending order:

            1 3 | 5 4 2

        Reverse it to make it the smallest possible order:

            1 3 | 2 4 5

        Final answer:

            1 3 2 4 5


    Main pattern:

        Find first decrease from right
                    ↓
        Find smallest greater element
                    ↓
                Swap them
                    ↓
        Reverse the suffix


    Important indexes:

        firstdec = position we increase

        smallestgreat = element used to increase it

        Reverse from:
            firstdec + 1

        Reverse until:
            nums.size() - 1


    Time Complexity:
        O(n)

    Space Complexity:
        O(1)
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int firstdec = -1 ;
        for(int i =nums.size()-2 ; i >= 0 ; i--){
            if(nums[i] < nums[i+1]){
                firstdec = i;
                break;
            }
        }
        if(firstdec == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int smallestgreat = -1;
        for(int i = nums.size() -1 ; i>= 0 ; i--){
            if(nums[i] > nums[firstdec]){
                smallestgreat = i;
                break;
            }
        }
    
        swap(nums[firstdec] , nums[smallestgreat]);
        int left = firstdec+1;
        int right = nums.size()-1;
        while(left <= right){
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            right--;
            left++;
        }
    }
};
