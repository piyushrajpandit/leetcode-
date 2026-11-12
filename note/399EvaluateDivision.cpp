class Solution {
public:
    unordered_map<string, unordered_map<string, double>> buildgraph(const vector<vector<string>> &equations, const vector<double>& values){
        unordered_map<string, unordered_map<string , double>> gr;
        for(int i =0 ; i< equations.size() ;i++){
            string divident = equations[i][0];
            string divisor= equations[i][1];
            double value = values[i];
            gr[divident][divisor] = value ;
            gr[divisor][divident] = 1.0/ value;
        }
         return gr;
    }
    void dfs(string node, string &dist, unordered_map<string, unordered_map<string, double>>& gr, unordered_set<string> & vis, double & ans , double temp){
        if(vis.find(node) != vis.end()) return ;
        vis.insert(node);

        if(node == dist){
            ans = temp;
            return ;
        }
        for(auto ne : gr[node]){
            dfs(ne.first,dist, gr, vis, ans, temp*ne.second);
            if(ans != -1.0 ) return;
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       
       unordered_map<string , unordered_map<string, double>> gr= buildgraph(equations,values);
       vector<double> finalanswer;
       for(auto query : queries){
        string dividend= query[0];
        string divisor = query[1];

        if(gr.find(dividend) == gr.end() || gr.find(divisor) == gr.end()){
            finalanswer.push_back(-1.0);
        }
        else{
            unordered_set<string> vis;
            double ans = -1, temp = 1.0;
            dfs(dividend, divisor, gr, vis, ans, temp);
            finalanswer.push_back(ans);
        }
       }
       return finalanswer;
    }
};
