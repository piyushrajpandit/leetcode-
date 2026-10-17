class Solution {
public:
    int minPartitions(string n) {
        int answer = 0;
        
        for(int i =0 ; i< n.size(); i++){
            answer = max(answer, n[i]- '0');
        }
        return answer;
    }
};
