class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int, int , int >>> rank;
        for(int i = 0 ;i< nums1.size(); i++){
            
            for(int j =0 ; j< nums2.size() ; j++){
                int sum = nums1[i] + nums2[j];
                rank.push({sum , nums1[i] , nums2[j]});
            }
        }
        vector<vector<int>> result;
        int count = 0;
        while(count< k && !rank.empty()){
            auto [sum, n1, n2] = rank.top();
            rank.pop();
            result.push_back({n1, n2});
            count++;
        }
        return result;
    }
};
/*
    Approach:
    - Use a min-heap to store possible pairs in the form:
      (sum, index1, index2).

    - Initially, pair nums1[0] with every element of nums2
      and insert all these pairs into the heap.

    - The smallest sum is always at the top of the min-heap.

    - Pop the smallest pair and add it to the result.

    - After popping (i, j), if another element exists in nums1,
      generate the next pair (i + 1, j) and push it into the heap.

    - Repeat until k pairs are collected.

    Key Idea:
    The heap always keeps the smallest available pair, and after
    removing a pair, we introduce the next possible pair.

    Time Complexity:
    O(n2 + k log(n2))

    Space Complexity:
    O(n2)

    Note:
    This is an improved approach over brute force because we don't
    generate all nums1.size() * nums2.size() pairs.
*/
class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int, int , int >>> rank;

        int temp = nums1[0];
        for(int i =0 ; i < nums2.size(); i++){
            rank.push({temp+ nums2[i], 0 ,i});
        }

        vector<vector<int>> result;
        int count = 0;
        
        while(count< k && !rank.empty()){
            auto [sum, n1, n2] = rank.top();
            rank.pop();
            result.push_back({nums1[n1], nums2[n2]});
            count++;
            if( n1 + 1< nums1.size()){
                    rank.push({sum - nums1[n1] + nums1[n1+1], n1+1, n2});
                
                    
            }
        }
        return result;
    }
};
