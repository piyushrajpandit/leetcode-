// LeetCode 57 - Insert Interval
//
// 1. Store the new interval's start and end in separate variables.
//    start = newInterval[0], end = newInterval[1]
//
// 2. Traverse all existing intervals.
//
// 3. If the current interval is completely before the new interval
//    (thisEnd < start), add it directly to the answer.
//
// 4. If the current interval overlaps the new interval
//    (thisStart <= end), merge them:
//    - start = min(start, thisStart)
//    - end   = max(end, thisEnd)
//
// 5. If the current interval is completely after the new interval,
//    first add the merged new interval, then add the current interval
//    and all remaining intervals.
//
// 6. Make sure the merged interval {start, end} is added only once.
//    Otherwise, it can appear twice in the answer.
//
// Time Complexity: O(n)
// Space Complexity: O(n) for the result.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int start = newInterval[0];
        int end = newInterval[1];
        bool inserted = false;
  
        for(int i = 0 ; i< intervals.size() ; i++){
            int thisStart = intervals[i][0];
            int thisEnd = intervals[i][1];
            if(thisEnd < start){
                answer.push_back({thisStart, thisEnd});
            }

            else if(thisStart <= end){
                start = min( start, thisStart);
                end = max(end , thisEnd);

            }
            else{
            answer.push_back({start, end});
            inserted = true;
            answer.push_back({thisStart, thisEnd});
            i++;
            while(i < intervals.size()){
                int thisStart = intervals[i][0];
                int thisEnd = intervals[i][1];
                answer.push_back({thisStart, thisEnd});
                i++;
                
            }
            break;
            }

        }
        if(!inserted)
        answer.push_back({start ,end});
        return answer;
    }
};
