// LeetCode 56 - Merge Intervals
// Approach: Sort intervals by starting position, then merge overlapping intervals.
//
// 1. Sort intervals by their start value.
//    Example: [2,3], [1,10] -> [1,10], [2,3]
//
// 2. Take the first interval as the current merged interval.
//    start = first interval's start
//    end   = first interval's end
//
// 3. For every next interval:
//    - If thisStart <= end, the intervals overlap.
//      Extend the current interval's end if thisEnd is larger.
//
//    - Otherwise, there is no overlap.
//      Store the current interval in answers,
//      then start a new interval.
//
// 4. After the loop, push the final merged interval.
//
// Why sort by start?
// Sorting by start lets us process intervals from left to right,
// making it easy to determine whether the next interval overlaps
// with the current merged interval.
//
// Time Complexity: O(n log n) because of sorting.
// Space Complexity: O(n) for the answer vector.
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answers;
        sort(intervals.begin(), intervals.end() , [](const vector<int>& a , const vector<int> & b){
            return a[0] < b[0];
        });
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i = 1 ; i< intervals.size() ; i++){
            int thisStart = intervals[i][0];
            int thisEnd = intervals[i][1];

            if(thisStart <= end){
                if(thisStart < start ) start = thisStart;
                if(thisEnd > end) end = thisEnd;
              
            }
            else{
                answers.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        answers.push_back({start,end});
        return answers;
    }
};
