class Solution {
public:
    static bool cmp(vector<int>& a, vector<int> &b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end() ,cmp);
        int count =1 ;
        int n = intervals.size();
        int ansEnd = intervals[0][1];
        for(int i =1 ;i<n; i++){
            if(intervals[i][0] >= ansEnd){
                count++;
                ansEnd = intervals[i][1];
            }
        }
        return n- count;
    }
};
