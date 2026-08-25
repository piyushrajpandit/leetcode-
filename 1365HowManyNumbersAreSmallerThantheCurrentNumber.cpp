/*
LeetCode 1365 - How Many Numbers Are Smaller Than the Current Number

Approach:
1. Make a copy of nums because we need to preserve the original order.
2. Sort the copy.
3. Create an unordered_map where:
       rank[value] = first index of value in the sorted array.

   The first index tells us how many elements are strictly
   smaller than that value.

4. Only store the first occurrence of each value:
       if(i == 0 || num[i-1] != num[i])
           rank[num[i]] = i;

   Do NOT update the map for duplicates, because all duplicates
   must have the same answer.

5. Traverse the original nums and use:
       rank[nums[i]]
   to get the answer for each element.

Example:
    nums   = [8, 1, 2, 2, 3]
    sorted = [1, 2, 2, 3, 8]

    rank:
        1 → 0
        2 → 1
        3 → 3
        8 → 4

    Answer:
        [4, 0, 1, 1, 3]

Time Complexity: O(n log n)
    Sorting takes O(n log n).

Space Complexity: O(n)
    Copy + unordered_map + result.
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> num = nums;
        sort(num.begin(), num.end());
        unordered_map<int , int> rank;
        for(int i =0; i< num.size(); i++){
            if(i==0 || num[i-1] != num[i]){
                rank[num[i]] = i;
            }
            
        }
        vector<int> ans;
        for(int i =0 ; i< nums.size() ; i++){
            int temp = rank[nums[i]];
            ans.push_back(temp);
        }
        return ans;
    }
};
