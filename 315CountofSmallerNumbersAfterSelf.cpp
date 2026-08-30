/*
    Approach: Modified Merge Sort

    - Store each element as:
      {value, originalIndex}

      This allows us to update the answer at the element's
      original position even after sorting.

    - Use Merge Sort to divide the array into two halves.

    - During the merge step:
        If right[j] < left[i]:
            The right element is smaller than the current
            left element, so increase `smaller`.

        Otherwise:
            Add `smaller` to ans[left[i].originalIndex].
            This means `smaller` elements from the right half
            are smaller than the current left element.

    - Equal values are NOT counted because we use:
      right[j].first < left[i].first

    - After merging, copy the sorted elements back into nums.

    Example:
      nums = [5,2,6,1]

      Answer = [2,1,1,0]

    Key Idea:
      During merging, count how many elements from the right
      half are smaller than each element from the left half.

    Time Complexity: O(n log n)
    Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> ans;
    vector<pair<int,int>> merge(vector<pair<int,int>>& left , vector<pair<int, int>>& right){
        int n = left.size();
        int m = right.size();
        int i =0 ;
        int j =0 ;
        int smaller = 0;
        vector<pair<int,int>> result;

        while(i < n && j < m){
          
            if(left[i].first <= right[j].first){
                result.push_back(left[i]);
                ans[left[i].second] += smaller;
                i++;
            }
            else{
                smaller++;
                result.push_back(right[j]);
                j++;
            }
            
        }
        while(i < n){
            ans[left[i].second] += smaller;
            result.push_back(left[i]);
            i++;
        }
         while(j < m){
            result.push_back(right[j]);
            j++;
        }
        return result;

    }
    vector<pair<int,int>> mergeSort(vector<pair<int,int>>&nums , int left, int right){
       
        if(left >= right){
            return {nums[left]};
        }
        int mid = left + (right - left) /2 ;
        vector<pair<int, int>> leftPart = mergeSort(nums, left, mid);
        vector<pair<int, int>> rightPart = mergeSort(nums , mid+ 1 , right);
        return merge(leftPart ,rightPart);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> index;
        for( int i =0 ; i< nums.size(); i++){
            index.push_back({nums[i], i});
        }
        ans.resize(nums.size(), 0);
        mergeSort(index , 0, index.size() -1 );

        return ans;
  
    }
};
