class Solution {
public:
    struct Compare {
        bool operator()(pair<int, string > a, pair<int, string> b){
            if(a.first == b.first)
                return a.second > b.second ;
            return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> answer;
        unordered_map<string, int> curr;
        for(string temp : words){
            curr[temp]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> maxheap;
        for(auto temp : curr){
            maxheap.push({temp.second, temp.first});
        }
        for(int i =0 ; i < k ; i++){
            auto temp = maxheap.top();
            maxheap.pop();
            answer.push_back(temp.second);
        }
        return answer;
    }
};
