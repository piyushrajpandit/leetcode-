class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> dq;
        for(int i =0 ; i< classes.size() ;i++){
            double p = classes[i][0];
            double t = classes[i][1];
            double gain = (p+1) / (t+ 1) - p/t;
            dq.push({gain, i});

            
        }
    while(extraStudents > 0){
        auto temp = dq.top();
        dq.pop();

        int idx = temp.second;
        classes[idx][0]++;
        classes[idx][1]++;

        double p = classes[idx][0];
        double t = classes[idx][1];

        double gain = (p+1)/(t+1) - p/t;
        dq.push({gain, idx});
        extraStudents--;

    }
    double ans= 0 ;
    for(auto &c: classes){
        ans += (double)c[0] / c[1];
    }

    return ans /classes.size();
    }

};
