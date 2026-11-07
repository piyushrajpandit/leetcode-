class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> dq;
        for(int i =0 ; i< points.size() ; i++){
            int distance = points[i][0]*points[i][0]  + points[i][1]*points[i][1];
            dq.push({distance, i});
            if(dq.size() > k){
                dq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!dq.empty()){
            ans.push_back(points[dq.top().second]);
            dq.pop();
        }
        return ans;
    }
};
