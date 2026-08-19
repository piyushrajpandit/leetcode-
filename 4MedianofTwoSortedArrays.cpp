/*

1. Binary search partition1 in nums1
        ↓
2. Calculate partition2
        ↓
3. Get four boundary values
        ↓
4. Check:
   nums1Left > nums2Right?
       → move left

   nums2Left > nums1Right?
       → move right

   otherwise:
       valid partition
        ↓
5. Calculate median


in this first we want nums2.size should be bigger one 
start a binary search this is advance bianay search 
make two partion first for mid of nums1 
and partion2 willl 
        int partion2 = (nums1.size() + nums2.size() +1 ) /2 - partion1;
        we added plus one because we want the left portion to contain one extra element when the total nunmber 
        of elements are is odd
now the heart 
nums1 = [1, 3, 8 | 10, 12]
              ↑
          partition1

nums2 = [2, 4 | 7, 9, 11]
             ↑
         partition2
        LEFT       |      RIGHT
nums1: [1, 3, 8]   |   [10, 12]
nums2: [2, 4]      |   [7, 9, 11]

nums1Left   nums1Right
nums2Left   nums2Right

how to find nums1Left 
so nums1[partion -1] is the thing and if partion is at the bigining so instead of accessing that
we use INT_MIN so if there is no left value we will pretend it to be negative infinity 
nums1Right is nums1[partion] and if its last element we wantto pretend it INT_MAX

now the last part nums1Left > nums2Right then move left   means we have more elemnet in left 
and nums2Left > nums1Right then move right   means move to right we have more element in right

look valid parentes conditon is 
nums1Left <= nums2Right
&&
nums2Left <= nums1Right is this

nums1: [ left side | right side ]
nums2: [ left side | right side ]

             ↓

ALL LEFT ELEMENTS <= ALL RIGHT ELEMENTS

so first check if total element is odd or even 
if its odd return max(nums1Left , nums2Left);

and if its even we will take 
leftmax = max(nus1left , nums2left);
rightMin = min( nums1Right, nums2right);
and return (left<ax + rightMin) /2.0;
*/



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        
        int left = 0 ;
        int right = nums1.size() ;
        while(left <= right){
        int partion1 = left + (right - left ) /2;
        int partion2 = (nums1.size() + nums2.size() +1 ) /2 - partion1;
        int nums1Left = (partion1 == 0 ) ? INT_MIN:  nums1[partion1-1];
        int nums2Left = (partion2 == 0) ? INT_MIN : nums2[partion2 -1];
        int nums1Right = (partion1 == nums1.size() ) ?INT_MAX : nums1[partion1];
        int nums2Right = (partion2 == nums2.size()) ? INT_MAX : nums2[partion2];
        if(nums1Left > nums2Right){
            right = partion1 - 1;
        }
        else if(nums2Left > nums1Right){
            left = partion1 + 1;
        }
        else{
            if((nums1.size() + nums2.size())%2 == 1){
                return max(nums1Left , nums2Left);
            }
            else{
                double leftMax = max(nums1Left , nums2Left);
                double rightMin = min(nums1Right, nums2Right);
                return (leftMax + rightMin) / 2.0;
            }
        }
        }
        return 0.0;
       
    }
};
