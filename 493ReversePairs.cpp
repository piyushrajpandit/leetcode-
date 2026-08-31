/*
LeetCode 493 - Reverse Pairs

Approach:
Use Merge Sort + Two Pointers to count reverse pairs in O(n log n).

Reverse pair condition:
    i < j
    AND
    nums[i] > 2 * nums[j]

1. mergeSort() divides the array into two halves recursively.

2. Each half is sorted before merging.

3. After getting:
       leftPart  = sorted left half
       rightPart = sorted right half

   Count reverse pairs between the two halves.

4. Use two pointers:
       i → leftPart
       j → rightPart

   For every leftPart[i], move j while:
       leftPart[i] > 2LL * rightPart[j]

   Since rightPart is sorted, every element before j
   forms a reverse pair with leftPart[i].

   Therefore:
       count += j

5. After counting reverse pairs, use the normal merge
   process to combine leftPart and rightPart into a sorted vector.

6. count is initialized once in reversePairs() so that
   the count accumulates across all recursive calls.

Important:
    Use 2LL * rightPart[j] to avoid integer overflow.

Normal merge:
    Compare leftPart[i] and rightPart[j]
    Take the smaller element first.

Complexity:
    Time  = O(n log n)
    Space = O(n)

Overall flow:
    Divide
       ↓
    Sort left + right
       ↓
    Count reverse pairs
       ↓
    Merge sorted halves
       ↓
    Return total count
*/

class Solution {
public:
    int count;
    vector<int> merge(vector<int> left , vector<int> right){
        vector<int> result;
        int n = left.size();
        int m = right.size();
        int i =0 ; 
        int j = 0 ;
    
        while(i < n && j < m){
            if(left[i] <= right[j]){
                result.push_back(left[i]);
               
                i++;
            }
            else{
            result.push_back(right[j]);
            j++;
            }
        }
        while(i < n){
            result.push_back(left[i]);
            i++;
        }
        while(j < m){
            result.push_back(right[j]);
            j++;
        }
        return result;

    }
    vector<int> mergeSort(vector<int> & nums, int left , int right){
        if(left>= right){
            return {nums[left]};
        }

        int mid = left + ( right - left) / 2;
        
        vector<int> leftPart = mergeSort(nums,left ,mid);
        vector<int> rightPart = mergeSort(nums, mid+1, right);
        int i =0 ; 
        int j = 0;
      
        for(int i =0 ; i< leftPart.size(); i++){
            while( j< rightPart.size() && leftPart[i] > 2LL * rightPart[j]){
                j++;
            }
            count += j;
        }
      
        return merge(leftPart ,rightPart);

    }
    int reversePairs(vector<int>& nums) {
       count = 0;
       mergeSort(nums , 0 , nums.size() -1 );
        return count;
    }
};
