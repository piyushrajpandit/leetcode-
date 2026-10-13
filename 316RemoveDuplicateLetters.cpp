class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        unordered_map<char ,bool> visited;
        string answer;
        for(int i =0 ; i< s.size() ;i++){
            freq[s[i]]++;
        }
        for(char c : s){
            freq[c]--;
            if(visited[c]){
                 continue;
            } 
            while(!answer.empty() && answer.back()> c && freq[answer.back()] >0 ){
                visited[answer.back()] = false;
                answer.pop_back();
            }
            answer += c;
            visited[c] = true;
        }


        
        return answer;
    }
};
