class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 1;
       
        sort(points.begin() , points.end(), [](const vector<int>& a , const vector<int> & b){
            return a[1] < b[1];
        });
        int start = points[0][0] ;
        int end = points[0][1];
        for(int i =1 ; i< points.size(); i++){
            int thisStart = points[i][0];
            int thisEnd = points[i][1];

            if( thisStart <= end){
                continue;
            }
            else{
                start = points[i][0];
                end = points[i][1];
                count++;
            }
        }
         return count;

    }
};
